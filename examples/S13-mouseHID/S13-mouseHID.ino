/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
|||||||||||||||||||||||
||    "Mouse HID"    ||
|||||||||||||||||||||||  
- Turns microcontroller into a USB mouse, a "Human-Interface-Device" or HID for short
- button 1 = left click
- button 2 = right click
- pot 1 = x move
- pot 2 = y move

- NOTE: You MUST set USB MODE to "USB-OTG (TinyUSB)" under Tools menu
- NOTE: you cannot use GPIO Pins 19 & 20 when using USB comms

REFERENCE:
https://docs.arduino.cc/libraries/mouse/
https://docs.arduino.cc/built-in-examples/usb/KeyboardAndMouseControl/
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

//include USB & Mouse libraries
#include "USB.h"
#include "USBHIDMouse.h"

//create mouse object
USBHIDMouse Mouse;

//Define Pins
const int adcPin_1 = 1;
const int adcPin_2 = 2;
const int buttonPin_1 = 12;
const int buttonPin_2 = 13;

//Button Variables
bool buttonState_1 = 0;
bool buttonState_2 = 0;

//Pot Variables
int adcRead_1 = 0;
int adcRead_2 = 0;
int offset = 32;

void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP); 
  pinMode(buttonPin_2, INPUT_PULLUP);
  analogReadResolution(8); 
  Serial.begin(115200); //start serial comm @ 115200 baud rate
  Mouse.begin();  //init mouse object
  USB.begin();  //init USB object
}

void loop() 
{
  //read analog pot value
  adcRead_1 = analogRead(adcPin_1);
  adcRead_2 = analogRead(adcPin_2);

  //read button states on pins [NOTE: logic is inverted due to Pullup config]
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  //map adc reads from 0 to 255 into -4 to 4 range
  float move_X = map(adcRead_1, 0, 255, -4, 4);
  float move_Y = map(adcRead_2, 0, 255, 4, -4);

  //move relative mouse position based on move x & y variables
  Mouse.move(move_X, 0);
  Mouse.move(0, move_Y);

  //NOTE: If you PRESS mouse button, you must RELEASE mouse button.
  if (buttonState_1)
  {
    Mouse.press(MOUSE_LEFT);  //press left mouse button
  }
  else 
  {
    Mouse.release(MOUSE_LEFT);  //release left mouse button
  }

  if (buttonState_2)
  {
    Mouse.press(MOUSE_RIGHT); //press right mouse button
  }
  else 
  {
    Mouse.release(MOUSE_RIGHT); //release right mouse button
  }
}
