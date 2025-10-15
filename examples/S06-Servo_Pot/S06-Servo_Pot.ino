/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||
||        "SERVO POT"         ||
||        by Ian Pokorny      ||
||          MTEC2280          ||
||||||||||||||||||||||||||||||||
- sets a Servo motor angle based on pot position

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

Servo myServo;    //create instance of Servo library object

const int servoPin = 9;
const int adcPin = 1;

int angle = 0;

void setup() 
{
  myServo.attach(servoPin); //attach servo object to physical pin
  
  analogReadResolution(8); //knocking resolution back to 8-bit to reduce jumpy pot read

  Serial.begin(115200);
}

void loop() 
{
  int adcRead = analogRead(adcPin);


  angle = map(adcRead, 0, 255, 0, 180); //map adcRead from 0-255 to 0-180 degrees
  
  myServo.write(angle); //move the servo motor to angle

  Serial.printf("ADC = %i \t ANGLE = %i \n", adcRead, angle);
}
