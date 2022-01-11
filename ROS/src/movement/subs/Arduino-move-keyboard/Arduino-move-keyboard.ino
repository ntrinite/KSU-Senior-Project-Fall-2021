#include <ros.h>
#include <ArduinoHardware.h>
//#include <Stepper.h>

#include <std_msgs/Int16.h>
#include <movement/Control.h>

//const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
//const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

////Stepper Motor
//int A = 8;
//int B = 9;
//int C = 10;
//int D = 11;

//Motor A
int PWMA = 2;   //Speed control pin 
int AIN1 = 23;   //Direction - HIGH or LOW
int AIN2 = 3;   //Direction - HIGH or LOW

//Motor B
int PWMB = 4;   //Speed control pin 5
int BIN1 = 5;  //Direction - HIGH or LOW
int BIN2 = 22;  //Direction - HIGH or LOW

// Front Right Sonar
int TRIG_FR = 52;
int ECHO_FR = 50;

// Front left Sonar
int TRIG_FL = 53;
int ECHO_FL = 51;

// Back Sonar
int TRIG_B = 22;
int ECHO_B = 23;

bool front_r_blocked = false;
bool front_l_blocked = false;
bool back_blocked = false;

ros::NodeHandle nh;

void callback(const movement::Control& cmd) {

  front_r_blocked = sonar_sensor(TRIG_FR, ECHO_FR);
  front_l_blocked = sonar_sensor(TRIG_FL, ECHO_FL);
  back_blocked = sonar_sensor(TRIG_B, ECHO_B);

  if(cmd.direction == 69)
  {
    nh.loginfo("Stepper up");
//    myStepper.setSpeed(700);
//    myStepper.step(stepsPerRevolution);
    int i = 0;
//    while(i < stepsPerRevolution) {
//      onestep();
//      i++;
//    }
  }

  if(cmd.direction == 420)
  {
    nh.loginfo("Stepper down");
//    myStepper.setSpeed(-700);
//    myStepper.step(-stepsPerRevolution);
  }


  if(cmd.direction == 8 && cmd.do_move /*&& (!front_r_blocked && !front_l_blocked)*/)
  { 
    nh.loginfo("going FOOOORRWWARDD");
//    nh.loginfo(cmd.direction);
//    nh.loginfo(cmd.speed);
//    if(cmd.do_move)
//    {
//      nh.loginfo("Movin'");
//    }
//    else{
//      nh.loginfo("Not Movin' :(");
//    } 
    
    //forward
    move(1, cmd.speed, 1, 8);
    move(2, cmd.speed, 0, 8); 
  }
  else if(cmd.direction == 2 && cmd.do_move /*&& !back_blocked*/)
  { 
    nh.loginfo("going BAACCCKKK");
//    nh.loginfo(cmd.direction);
//    nh.loginfo(cmd.speed);
//    if(cmd.do_move)
//    {
//      nh.loginfo("Movin'");
//    }
//    else{
//      nh.loginfo("Not Movin' :(");
//    }
//    
    //back
    move(1, cmd.speed, 1, 2);
    move(2, cmd.speed, 0, 2); 
  }
  else if(cmd.direction == 4 && cmd.do_move /*&& !front_l_blocked*/)
  { 
    nh.loginfo("going LEEEEFFFTTT");
//    nh.loginfo(cmd.direction);
//    nh.loginfo(cmd.speed);
//    if(cmd.do_move)
//    {
//      nh.loginfo("Movin'");
//    }
//    else{
//      nh.loginfo("Not Movin' :(");
//    }
    
    //left 
    move(1, cmd.speed, 1, 4);
    move(2, cmd.speed, 0, 4); 

  }
   else if(cmd.direction == 6 && cmd.do_move /*&& !front_r_blocked*/)
  { 
    nh.loginfo("going RIIIIIIGHT");
//    nh.loginfo(cmd.direction);
//    nh.loginfo(cmd.speed);
//    if(cmd.do_move)
//    {
//      nh.loginfo("Movin'");
//    }
//    else{
//      nh.loginfo("Not Movin' :(");
//    }
    
    //Right
    move(1, cmd.speed, 1, 6);
    move(2, cmd.speed, 0, 6); 
  }
  else {
//    nh.loginfo(cmd.data);
    move(1, cmd.speed, 1, 0);
    move(2, cmd.speed, 0, 0); 
//    nh.loginfo(cmd.direction);
//    nh.loginfo(cmd.speed);

    nh.loginfo("STOPPING");
  }
    
}

void move(int motor, int speed, int direction, int movement_dir)
{
      boolean inPin1 = LOW;
//      boolean inPin2 = LOW;
      boolean inPin2 = HIGH;

      if(direction == 1){
            inPin1 = HIGH;
//            inPin2 = HIGH;
            inPin2 = LOW;
      }



/*
 * BASING EVERYTHING OFF OF THESE TWO COMMANDS BECAUSE IT'S EASIER TO DEBUG
 *  move(1, cmd.speed, 1);
    move(2, cmd.speed, 0);
 */

//
////BACK ISN'T WORKING
//      if(motor == 1) {
//            digitalWrite(AIN2, inPin1);         //Used to detremine motor direction
//            digitalWrite(BIN1, inPin2);         //Used to detremine motor direction
//            analogWrite(PWMA, speed);     
//      } else if(motor ==2) { // motor ==2
//            digitalWrite(AIN2, inPin1);         //Used to detremine motor direction
//            digitalWrite(BIN1, inPin2);         //Used to detremine motor direction
//            analogWrite(PWMB, speed);
//      }


//RIIIIIIIIIIIIIIIGHHHHHHHHHHHTTTTTTTTTTTT
  if(movement_dir == 6)
  {
    nh.loginfo("Move dir is 6");
      if(motor == 1) {
            digitalWrite(AIN2, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN1, inPin2);         //Used to detremine motor direction
            analogWrite(PWMA, speed);     
      } else if(motor ==2) { // motor ==2
            digitalWrite(AIN1, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN2, inPin2);         //Used to detremine motor direction
            analogWrite(PWMB, speed);
      }
  }


      ///////////****************left *****************************///
  if(movement_dir == 4)
  {
    nh.loginfo("move dir is 4");
      if(motor == 1) {
            digitalWrite(AIN1, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN2, inPin2);         //Used to detremine motor direction
            analogWrite(PWMA, speed);     
      } else if(motor ==2) { // motor ==2
            digitalWrite(AIN2, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN1, inPin2);         //Used to detremine motor direction
            analogWrite(PWMB, speed);
     }
  }

     //************888motor forward****************************//

  if(movement_dir == 8)
  {
    nh.loginfo("move dir is 8");
           if(motor == 1) {
            digitalWrite(AIN2, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN2, inPin2);         //Used to detremine motor direction
            analogWrite(PWMA, speed);     
      } else if(motor ==2) { // motor ==2
            digitalWrite(AIN1, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN1, inPin2);         //Used to detremine motor direction
            analogWrite(PWMB, speed);
      }
  }
  else
  {
    nh.loginfo("nothing is working");
    if(motor == 1) {
            digitalWrite(AIN2, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN2, inPin2);         //Used to detremine motor direction
            analogWrite(PWMA, 0);     
      } else if(motor ==2) { // motor ==2
            digitalWrite(AIN1, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN1, inPin2);         //Used to detremine motor direction
            analogWrite(PWMB, 0);
      }
  }
}

bool sonar_sensor(int trig_pin, int echo_pin)
{
  float duration, inches;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
//  String duration_print = String(duration);
  inches = duration/74/2;
//  String inches_print = String(inches);
//  nh.loginfo(inches_print.c_str());

  if(inches <=4)
  {
    return true; // blocked
  }
  else{
    return false; // not blocked
  }
}

//void write(int a,int b,int c,int d){
//digitalWrite(A,a);
//digitalWrite(B,b);
////digitalWrite(C,c);
////digitalWrite(D,d);
//}
//
//void onestep(){
//write(1,0,0,0);
//delay(5);
//write(1,1,0,0);
//delay(5);
//write(0,1,0,0);
//delay(5);
//write(0,1,1,0);
//delay(5);
//write(0,0,1,0);
//delay(5);
//write(0,0,1,1);
//delay(5);
//write(0,0,0,1);
//delay(5);
//write(1,0,0,1);
//delay(5);
//}
//                 
//ros::Subscriber<std_msgs::Int16> dir_sub("cmd_v/el", &callback);
ros::Subscriber<movement::Control> controller_sub("move", &callback);

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  nh.initNode();
  nh.subscribe(controller_sub);

//  myStepper.setSpeed(300);
//
//  pinMode(A, OUTPUT);        //Stepper
//  pinMode(B, OUTPUT);
//  pinMode(C, OUTPUT);
//  pinMode(D, OUTPUT);
  
  pinMode(PWMA, OUTPUT);        //Motor A
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);        //Motor B
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // Front Right sensor
  pinMode(TRIG_FR, OUTPUT);
  pinMode(ECHO_FR, INPUT);

  // Left Right sensor
  pinMode(TRIG_FL, OUTPUT);
  pinMode(ECHO_FL, INPUT);

  // Back sensor
  pinMode(TRIG_B, OUTPUT);
  pinMode(ECHO_B, INPUT);
  nh.loginfo("setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
//  nh.loginfo("wow");
  nh.spinOnce();
  delay(1);
}
