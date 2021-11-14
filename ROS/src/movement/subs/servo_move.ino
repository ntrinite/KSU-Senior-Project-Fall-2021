#include <ros.h>
#include <ArduinoHardware.h>

#include <std_msgs/Int16.h>
#include <Servo.h>

ros::NodeHandle nh;
Servo test_servo;

void callback(const std_msgs::Int16& cmd) {
  test_servo.write(cmd.data); //set servo angle, should be from 0-180
    
}

ros::Subscriber<std_msgs::Int16> sub("cmd_vel", &callback);

void setup() {
  
  test_servo.attach(9);
  test_servo.write(0);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  delay(1);
}
