//////////////////////////////////////////////////////////////////////////////////////////
/*
   Pair with Processing motor sketch, to control servo with Processing interface.
*/
//////////////////////////////////////////////////////////////////////////////////////////

#include <ESP32Servo.h>  //include ESP32 Servo library

Servo servo;  //creates new Servo object called servo

const int SERVOPIN = 9;
int angle = 0;  // Tracks servo position in degrees
int val = 0;    // Tracks incoming value from Serial port
int speed = 5;   // speed of servo motor sweep, adjust to taste

void setup() 
{
  servo.attach(SERVOPIN);  // attach servo pin to servo object
  Serial.begin(9600);    // Start serial communication at 115200 bps
}

void loop() 
{
  if (Serial.available()) // if data is available to read...
  {  
    val = Serial.read();  // ...read it and store it in val
  } 

  if (val == 255) // if val is 255, sweep motor
  {
    val = 0;  //reset val;

    for (angle = 0; angle <= 180; angle++) 
    {
      servo.write(angle); // scan from 0 to 180 degrees
      delay(speed);       // delay for each angle
    }
    
    for (angle = 180; angle >= 0; angle--) 
    {
      servo.write(angle); // scan back from 180 to 0 degrees
      delay(speed);       // delay for each angle
    }
  }
  else  // if val does not equal 255...
  {           
    servo.write(val);  // ...set servo angle to val
  }
}