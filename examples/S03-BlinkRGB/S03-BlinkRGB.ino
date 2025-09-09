/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
  BlinkRGB

  - Demonstrates usage of onboard RGB LED on ESP32-S3 dev boards.
  - RGB LED @ GPIO Pin 38
  - There is a library for the RGB LED provided in the ESP framework.
  - library provides the function RGBLedWrite:
  void rgbLedWrite(uint8_t pin, uint8_t red_val, uint8_t green_val, uint8_t blue_val)
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/
const uint8_t pinRGB = 38;
uint8_t brightness = 4; //max is 255, very bright!
uint16_t delayTime = 1000;

void setup() 
{
  //typically you need to set LED pinMode to OUTPUT...
  //...but we are using a library that takes care of that for us.
}

// the loop function runs over and over again forever
void loop() 
{
  rgbLedWrite(pinRGB, brightness, brightness, brightness);  // White
  delay(delayTime);
  rgbLedWrite(pinRGB, brightness, 0, 0);  // Red
  delay(delayTime);
  rgbLedWrite(pinRGB, 0, brightness, 0);  // Green
  delay(delayTime);
  rgbLedWrite(pinRGB, 0, 0, brightness);  // Blue
  delay(delayTime);
  rgbLedWrite(pinRGB, brightness, brightness, 0);  // Yellow
  delay(delayTime);
  rgbLedWrite(pinRGB, brightness, 0, brightness);  // Magenta
  delay(delayTime);
  rgbLedWrite(pinRGB, 0, brightness, brightness);  // Cyan
  delay(delayTime);
}
