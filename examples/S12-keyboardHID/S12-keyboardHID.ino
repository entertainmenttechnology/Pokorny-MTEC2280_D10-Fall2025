/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
|||||||||||||||||||||||
||    "Mouse HID"    ||
|||||||||||||||||||||||  
- Turns microcontroller into a USB keyboard, a "Human-Interface-Device" or HID for short
- button 1 = A
- button 2 = Z

- NOTE: You MUST set USB MODE to "USB-OTG (TinyUSB)" under Tools menu
- NOTE: you cannot use GPIO Pins 19 & 20 when using USB comms

REFERENCE:
https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/
https://docs.arduino.cc/built-in-examples/usb/KeyboardAndMouseControl/
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

//include USB & Keyboard libraries
#include "USB.h"
#include "USBHIDKeyboard.h"

//create keyboard object
USBHIDKeyboard Keyboard;

//Define Pins
const int buttonPin_1 = 12;
const int buttonPin_2 = 13;

//Button Variables
bool buttonState_1 = 0;
bool buttonState_2 = 0;
bool prevButtonState_1 = 0;
bool prevButtonState_2 = 0;

void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP); 
  pinMode(buttonPin_2, INPUT_PULLUP); 
  Serial.begin(115200); //start serial comm @ 115200 baud rate
  Keyboard.begin(); //init keyboard object
  USB.begin();  //init USB object
}

void loop() 
{
  buttonState_1 = !digitalRead(buttonPin_1);  //read button state 1
  buttonState_2 = !digitalRead(buttonPin_2);  //read button state 2

  if (buttonState_1 && !prevButtonState_1)  //if rising edge detected...
  {
    Keyboard.write('A');  //send keypress of 'A'
    //you can also use Keyboard.print('A') or Keyboard.println('A') if you want a newline afterwards
  }
  prevButtonState_1 = !digitalRead(buttonPin_1);
  
  if (buttonState_2 && !prevButtonState_2)  //if rising edge detected...
  {
    Keyboard.write('Z');  //send keypress of 'Z'
  }
  prevButtonState_2 = !digitalRead(buttonPin_2);
  
  delay(5); //slight delay to remove button debounce noise
}