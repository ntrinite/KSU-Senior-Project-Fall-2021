#include <ros.h>
#include <ArduinoHardware.h>

#include <std_msgs/String.h>

//Motor A
int PWMA = 2;   //Speed control pin 
int AIN1 = 23;   //Direction - HIGH or LOW
int AIN2 = 3;   //Direction - HIGH or LOW

//Motor B
int PWMB = 4;   //Speed control pin 5
int BIN1 = 5;  //Direction - HIGH or LOW
int BIN2 = 22;  //Direction - HIGH or LOW

ros::NodeHanle nh;

void callback(const std_msgs::String& cmd) {
  if(cmd.data.equals("Forward")
  { 
    move(1, 100, 0);
    move(2, 100, 0);
  }
  else if(cmd.data.equals("Down")
  { 
    move(1, 100, 1);
    move(2, 100, 1);
  }
  else if(cmd.data.equals("Left")
  { 
    move(1, 100, 1);
    move(2, 100, 0);
  }
   else if(cmd.data.equals("Right")
  { 
    move(1, 100, 0);
    move(2, 100, 1);
  }
    
}

void move(int motor, int speed, int direction)
{
      boolean inPin1 = LOW;
      boolean inPin2 = HIGH;

      if(direction == 1){
            inPin1 = HIGH;
            inPin2 = LOW;
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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nh.initNode();
  nh.subscribe(sub);
  
  pinMode(PWMA, OUTPUT);        //Motor A
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);        //Motor B
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(1);
}
