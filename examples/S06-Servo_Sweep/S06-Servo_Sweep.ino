/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||
||        "SERVO SWEEP"       ||
||        by Ian Pokorny      ||
||          MTEC2280          ||
||||||||||||||||||||||||||||||||
- Sweeps a Servo motor from 0-180 degrees and back again

- Connect your Servo:
  RED = 5V
  BROWN = GND
  ORANGE = ServoPin
    *NOTE: these colors may vary depending on manufacturer

- We can use library to adjust the angle of our DC Servo Motor:
ESP32 SERVO LIBRARY:
https://github.com/madhephaestus/ESP32Servo/tree/master
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

#include <ESP32Servo.h> //must include this library to use Servo Motor

Servo myServo;  //create instance of Servo library object

const int servoPin = 9; //pin we will connect Servo to 

int angle = 0;  //angle of Servo motor
int dir = 1;    //direction to sweep
int ms = 50;    //delay time

void setup() 
{
  myServo.attach(servoPin); //attach servo object to physical pin

  Serial.begin(115200);

}

void loop() 
{
  angle += dir; //increment angle based on direction
  if (angle >= 180 || angle <= 0) //if angle is outside of 0-180 range...
  {
    dir = -dir; //change direction
    Serial.println("REVERSE DIRECTION");
  }

  myServo.write(angle); //move the servo motor to angle

  delay(ms);  //wait...only here to slow down sweep rate

  Serial.println(angle);
}
