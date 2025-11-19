/*
  ||||||||||||||||||||||||||||||||||||
  ||        BUTTON - OOP STYLE      ||
  ||  Implementing Buttons w/ Class ||
  ||||||||||||||||||||||||||||||||||||
  - Reading Buttons using an Object Oriented Programming (O.O.P.) approach.
  - Includes a Button Class to handle:
    - setting pinMode().
    - digitalRead() on GPIO pins.
    - button logic: momentary press, toggling switch, rising & falling edges (aka press & release).
  - See Button.h include file for more info

  NOTE: include files that are not installed via library (like this one) must be copied into arduino project folder
*/

#include "Button.h" //include button class header file

//declare button pins
const int button1_pin = 1;
const int button2_pin = 2;

//declare global button variables
bool b1_state;
bool b2_state;
bool b1_toggle;
bool b2_toggle;

// Create new button objects from Button class
Button button1(button1_pin, INPUT_PULLUP);
Button button2(button2_pin, INPUT_PULLUP);

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{ 
  //update buttons: read pin, store state in object variable, compare to previous state, toggle logic.
  button1.update();
  button2.update();
  
  //store current button states in global variables.
  //we are accessing PRIVATE variables in objects using .pressed() and .toggle() methods, which are PUBLIC methods
  b1_state = button1.pressed(); 
  b2_state = button2.pressed();
  b1_toggle = button1.toggle();
  b2_toggle = button2.toggle();

  if(button1.risingEdge())
  {
    Serial.println("BUTTON 1 PRESS"); //print PRESS message if rising edge detected
  }

  if(button1.fallingEdge())
  {
    Serial.println("BUTTON 1 RELEASE"); //print RELEASE message if falling edge detected
  }

  if(button2.risingEdge())
  {
    Serial.println("BUTTON 2 PRESS"); //print PRESS message if rising edge detected
  }

  if(button2.fallingEdge())
  {
    Serial.println("BUTTON 2 RELEASE"); //print RELEASE message if falling edge detected
  }
  Serial.printf("B1 State = %d\tB1 Toggle = %d\tB2 State = %d\tB2 Toggle = %d\n",b1_state, b1_toggle, b2_state, b2_toggle);
}