//www.elegoo.com
//2016.12.12

#include "Stepper.h"
#include "IRremote.h"

/*----- Variables, Pins -----*/
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution
int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 6

/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4

//Motor A
int PWMA = 2;   //Speed control pin 
int AIN1 = 23;   //Direction - HIGH or LOW
int AIN2 = 3;   //Direction - HIGH or LOW

//Motor B
int PWMB = 4;   //Speed control pin 5
int BIN1 = 5;  //Direction - HIGH or LOW
int BIN2 = 22;  //Direction - HIGH or LOW

int mtrSpeed = 100; //regular robot speed
int turnSpeed = 200;    //faster speed used to turn robot


// Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

void setup()
{ 
  Serial.begin(9600); //Setup Serial monitor for 9600 baud
  irrecv.enableIRIn(); // Start the receiver

  pinMode(PWMA, OUTPUT);        //Motor A
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);        //Motor B
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop()
{
if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)

    {
      case 0xFF629D: //VOL+ is pressed
        move(1, mtrSpeed, 0); //move motor 1 clockwise 
        move(2, mtrSpeed, 0); //move motor 2 clockwise
        delay(1000); //delay for 1 second to decide next move
        break;
        
      case 0xFF22DD: //Fast back button is pressed
        move(1, mtrSpeed, 1); //move motor 1 counter clockwise
        move(2, mtrSpeed, 0); //move motor 2 clockwise
        delay(1000); //delay for 1 second to decide next move
        break;

      
      case 0xFFC23D: //Fast Forward button is pressed
        move(1, mtrSpeed, 0); //move motor 1 clockwise
        move(2, mtrSpeed, 1); //move motor 2 counter clockwise
        delay(1000); //delay for 1 second to decide next move
        break;

      
      case 0xFFA857: //VOL- is pressed
        move(1, mtrSpeed, 1); //move motor 1 counter clockwise
        move(2, mtrSpeed, 1); //move motor 2 counter clockwise
        delay(1000); //delay for 1 second to decide next command
        break;

      
/*
      case 0xFFA857: // VOL+ button pressed
                      small_stepper.setSpeed(500); //Max seems to be 500
                      Steps2Take  =  2048;  // Rotate CW
                      small_stepper.step(Steps2Take);
                      delay(2000); 
                      break;
                      */
/*
      case 0xFF629D: // VOL- button pressed
                      small_stepper.setSpeed(500);
                      Steps2Take  =  -2048;  // Rotate CCW
                      small_stepper.step(Steps2Take);
                      delay(2000); 
                      break;
                      */
                
    }
    
      irrecv.resume(); // receive the next value
                 digitalWrite(8, LOW);
                 digitalWrite(9, LOW);
                 digitalWrite(10, LOW);
                 digitalWrite(11, LOW);       
  }  


}/* --end main loop -- */

/*
 * Move motor logic
 */
void move(int motor, int speed, int direction) {

/*Move specific motor at speed and direction
*     motor: 1 for Motor A, 2 for motor B
*     speed: 0 is off, and 255 is full speed
*     direction: 0 clockwise, 1 counter-clockwise
*/

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
