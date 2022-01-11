#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h>

int MOTOR_PIN = 4;
int RIGHT_LED = 37;
int CENTER_LED = 41;
int LEFT_LED = 31;

Servo motor;

ros::NodeHandle nh;

void callback(const std_msgs::Int16& cmd) {
  if(cmd.data == 1) //
  {
//    digitalWrite(RIGHT_LED, HIGH);
//    digitalWrite(CENTER_LED, LOW);
//    digitalWrite(LEFT_LED, LOW);
    int val_1 = -31;
    delay(10000);
    motor.write(map(val_1, -100, 100, 1000, 2000));
    delay(10000);
//      motor.write(1600);
    nh.loginfo("RIGHT");
//    
  }
  else if (cmd.data == 0)
  {
//    digitalWrite(RIGHT_LED, LOW);
//    digitalWrite(CENTER_LED, LOW);
//    digitalWrite(LEFT_LED, HIGH);
    int val_2 = 30.5;
    delay(10000);
    motor.write(map(val_2, -100, 100,1000, 2000));
    delay(10000);
//    motor.write(1200);
    nh.loginfo("LEFT");
  }
  else {
////    int val_3 = 0;
////  motor.write(map(val_3, -100, 100,1000, 2000));
//    digitalWrite(CENTER_LED, HIGH);
//    digitalWrite(RIGHT_LED, LOW);
//    digitalWrite(LEFT_LED, LOW);
    motor.write(0);
    nh.loginfo("CENTER");
  }
//    
}

int move_motor(int val)
{
  motor.write(map(val, -100, 100,1000, 2000));
  delay(10000);
}

ros::Subscriber<std_msgs::Int16> cam_track("Track", &callback);

void setup() {
//  Serial.begin(57600);
//  nh.getHardware()->setBaud(57600);
  nh.loginfo("init node");
  nh.initNode();
  nh.loginfo("subscribing");
  nh.subscribe(cam_track);
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);
  motor.attach(MOTOR_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
//  move_motor(30);
//  delay(1);

}
