#include <Servo.h>

Servo Xservo;

int Xpin = A0;   //Joystick in x direction
int XSpin = 9;  //Servo pin
int Xval;
int dt = 100; //Delay
int WVx; //Calculated conversion from joystick to servo;

//The range of the joystick in the x and y is 0 to 1023;
// Default joystick values are Xval = 511 and Yval = 534
//The servo goes from 0 to 180

void setup() {
  Serial.begin(9600);
  pinMode(Xpin, INPUT);
  pinMode(XSpin, OUTPUT);

  Xservo.attach(XSpin);

}

void loop() {
  Xval = analogRead(Xpin);
  WVx = (180./1023.)*Xval;  //Proportion conversion
  
  Xservo.write(WVx);
  
  delay(dt);

}
