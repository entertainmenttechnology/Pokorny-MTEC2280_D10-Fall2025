/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
|||||||||||||||||||||||||||||||
||    " Mouse HID MAGIC!"    ||
|||||||||||||||||||||||||||||||
- Turns microcontroller into a USB mouse with some novel behavior!
- Open any drawing program (see related processing sketch) to see results 
- Mouse follows a "polar plot" around current absolute mouse position

- button 1 = turn on circular mouse motion and press down left mouse
- button 2 = send keyboard message (open text editor and press to see results)
- pot 1 = radius
- pot 2 = y move

- NOTE: You MUST set USB MODE to "USB-OTG (TinyUSB)" under Tools menu
- NOTE: you cannot use GPIO Pins 19 & 20 when using USB comms

REFERENCE:
https://docs.arduino.cc/libraries/mouse/
https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/
https://docs.arduino.cc/built-in-examples/usb/KeyboardAndMouseControl/
https://processing.org/examples/polartocartesian.html
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/
//include USB, Keyboard, & Mouse libraries
#include "USB.h"
#include "USBHIDMouse.h"
#include "USBHIDKeyboard.h"

//create mouse & keyboard objects
USBHIDMouse Mouse;
USBHIDKeyboard Keyboard;

//Define Pins
const int adcPin_1 = 1;
const int adcPin_2 = 2;
const int buttonPin_1 = 12;
const int buttonPin_2 = 13;
const int ledPin = 4;

//Button Variables
bool buttonState_1 = 0;
bool buttonState_2 = 0;
bool buttonToggle_1 = 0;
bool buttonToggle_2 = 0;
bool prevButtonState_1 = 0;
bool prevButtonState_2 = 0;

//Pot Variables
int adcRead_1 = 0;
int adcRead_2 = 0;

int xPos;
int yPos;
float angle = 0;
float radius = 10;
float rate = 0.01;

void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP); 
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  analogReadResolution(8); 
  Serial.begin(115200); //start serial comm @ 115200 baud rate
  Mouse.begin();  //init mouse object
  Keyboard.begin(); //init keyboard object
  USB.begin();  //init USB object
}

void loop() 
{
  //read analog pot value
  adcRead_1 = analogRead(adcPin_1);
  radius = map(adcRead_1, 0, 255, 1, 20); //map pot 1 to radius of circular motion
  adcRead_2 = analogRead(adcPin_2); 
  rate = floMap(adcRead_2, 0, 255, 0.005, 0.05);  //map to FLOAT the rate of circular motion

  //read button state on pins & toggle logic [NOTE: logic is inverted due to Pullup config]
  buttonState_1 = !digitalRead(buttonPin_1);
  if (buttonState_1 && !prevButtonState_1)
  {
    buttonToggle_1 = !buttonToggle_1;
  }
  prevButtonState_1 = !digitalRead(buttonPin_1);

  digitalWrite(ledPin, buttonToggle_1); //turn on/off LED to indicate when we are controlling mouse position

  buttonState_2 = !digitalRead(buttonPin_2);
  if (buttonState_2 && !prevButtonState_2)
  {
    buttonToggle_2 = !buttonToggle_2;
  }
  prevButtonState_2 = !digitalRead(buttonPin_2);

  if (buttonToggle_1)
  {
    //deriving x and y positions from cosine and sine results in a circular path
    xPos = radius * cos(angle); 
    yPos = radius * sin(angle);
    Mouse.press(MOUSE_LEFT);  //press left mouse button
    Mouse.move(xPos, yPos); //move mouse relative position based on derived circular x & y positions
    angle += rate;  //angle continues to increase at rate
  }
  else 
  {
    Mouse.release(MOUSE_LEFT);  //release left mouse button when button 1 toggled off
  }

  if (buttonState_2)
  {
    //print long message with newlines when button 2 is pressed
    Keyboard.println("Hello World,");
    Keyboard.println("This is a message from your ESP32 MCU using USB HID.");
    Keyboard.println("You can print out whole strings of text in one command.");
    Keyboard.println("Goodbye!");
  }
}

// user-defined function that accepts an integer and maps it to a new FLOATING POINT range
float floMap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}