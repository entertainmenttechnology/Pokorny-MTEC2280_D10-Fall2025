/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||
||  "SERVO POT - RANGED-pt.I" ||
||        by Ian Pokorny      ||
||          MTEC2280          ||
||||||||||||||||||||||||||||||||
- We can treat an analog pot more like a "switch" by setting ranges. This is one approach...

- If we don't want the pot to have full range of angles:
  - we can set specific angle values in array
  - we can adjust our pot read to only have 4 possible positions
  - we can use that pot value to pick different array elements

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

#include <ESP32Servo.h>   //must include this library to use Servo Motor

Servo myServo;    //create instance of Servo library object

const int servoPin = 9;
const int adcPin = 1;

int angles[4] = {45, 90, 135, 180};   //array for storing angle values
int servoAngle = 0;

void setup() 
{
  myServo.attach(servoPin);
  
  analogReadResolution(2);  //reduce resolution to 2-bit, range limited to 0-3
  //NOTE: this affects all ADC reads, so be aware

  Serial.begin(115200);
}

void loop() 
{
  int adcRead = analogRead(adcPin);

  //since our adcRead can only equal between 0-3, we just have to choose an array element based on that number
  if (adcRead == 1)
  {
    servoAngle = angles[1];
  }
  else if (adcRead == 2) 
  {
    servoAngle = angles[2];
  }
  else if (adcRead == 3)
  {
    servoAngle = angles[3];
  }
  else
  {
    servoAngle = angles[0];
  }
 
  myServo.write(servoAngle);

  Serial.printf("ADC = %i \t ANGLE = %i \n", adcRead, servoAngle);
}
