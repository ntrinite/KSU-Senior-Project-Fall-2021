#include <ros.h>
#include <ArduinoHardware.h>

#include <std_msgs/Int16.h>
#include <movement/Control.h>

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

  if(cmd.direction == 8 && cmd.do_move && (!front_r_blocked && !front_l_blocked))
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
    move(1, cmd.speed, 1);
    move(2, cmd.speed, 0);
  }
  else if(cmd.direction == 2 && cmd.do_move && !back_blocked)
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
    move(1, -cmd.speed, 0);
    move(2, -cmd.speed, 1);
  }
  else if(cmd.direction == 4 && cmd.do_move && !front_l_blocked)
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
    move(1, -cmd.speed, 1);
    move(2, cmd.speed, 1);

  }
   else if(cmd.direction == 6 && cmd.do_move && !front_r_blocked)
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
    move(1, cmd.speed, 0);
    move(2, -cmd.speed, 0);
  }
  else {
//    nh.loginfo(cmd.data);
    move(1, cmd.speed, 0);
    move(2, cmd.speed, 1);
//    nh.loginfo(cmd.direction);
//    nh.loginfo(cmd.speed);
    if(front_r_blocked)
    {
      nh.loginfo("Movin'");
    }
    else{
      nh.loginfo("Not Movin' :(");
    }

    nh.loginfo("STOPPING");
  }
    
}

void move(int motor, int speed, int direction)
{
      boolean inPin1 = LOW;
      boolean inPin2 = LOW;
//      boolean inPin2 = HIGH;

      if(direction == 1){
            inPin1 = HIGH;
            inPin2 = HIGH;
//            inPin2 = LOW;
      }

      if(motor == 1) {
            digitalWrite(AIN1, inPin1);         //Used to detremine motor direction
            digitalWrite(AIN2, inPin2);         //Used to detremine motor direction
            analogWrite(PWMA, speed);     
      } else {
            digitalWrite(BIN1, inPin1);         //Used to detremine motor direction
            digitalWrite(BIN2, inPin2);         //Used to detremine motor direction
            analogWrite(PWMB, speed);
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
                 
//ros::Subscriber<std_msgs::Int16> dir_sub("cmd_v/el", &callback);
ros::Subscriber<movement::Control> controller_sub("move", &callback);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nh.initNode();
  nh.subscribe(controller_sub);
  
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
