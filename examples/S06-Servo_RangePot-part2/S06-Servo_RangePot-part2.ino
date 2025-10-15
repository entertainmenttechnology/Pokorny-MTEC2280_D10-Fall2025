/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||
|| "SERVO POT - RANGED-pt.II" ||
||        by Ian Pokorny      ||
||          MTEC2280          ||
||||||||||||||||||||||||||||||||
- We can treat an analog pot more like a "switch" by setting ranges. This is another approach...

- If we don't want the pot to have full range of angles:
  - we can set specific angle values in array
  - we can use if && logic to set specific bounded ranges for choosing our values from array

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

#include <ESP32Servo.h> 

Servo myServo;

const int servoPin = 9;
const int adcPin = 1;

int angles[4] = {45, 90, 135, 180};
int servoAngle = 0;

void setup() 
{
  myServo.attach(servoPin);
  
  analogReadResolution(12);

  Serial.begin(115200);
}

void loop() 
{
  int adcRead = analogRead(adcPin);

  if (adcRead < 1023) //if adcRead is between 0-1023
  {
    servoAngle = angles[0];
  }
  else if (adcRead > 1023 && adcRead < 2049) //if adcRead is between 1023-2049
  {
    servoAngle = angles[1];
  }
  else if (adcRead > 2049 && adcRead < 3072) //if adcRead is between 2049-3072
  {
    servoAngle = angles[2];
  }
  else if (adcRead > 3072)  //if adcRead is between 3072-4095
  {
    servoAngle = angles[3];
  }
 
  myServo.write(servoAngle);

  Serial.printf("ADC = %i \t ANGLE = %i degrees \n", adcRead, servoAngle);
}
