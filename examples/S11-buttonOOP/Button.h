/*
||||||||||||||||||||||||||||||||||||||||||||||
||      "Simple Arduino Button Class"       ||
||              by Ian Pokorny              ||
||||||||||||||||||||||||||||||||||||||||||||||
- This is a simple Arduino IDE button class that handles button input.
- It can be initialized with any digital GPIO pin in either PullUp or PullDown mode, defaulting to PullUp.
- The class handles button state, toggle state, and rising/falling edge detection.
- IMPORTANT: update() method must be called in the main loop to check button state.
*/

#ifndef BUTTON_H  // This is a header guard to prevent multiple inclusions of this file.
#define BUTTON_H  // Defining BUTTON_H here to prevent it from being included from some other source.

#include <Arduino.h>  // Include the Arduino library for basic functions like pinMode() and digitalRead().

class Button 
{
  private:  // The private section contains variables and methods that are NOT accessible outside the class.
    
    uint8_t _pin;   // The GPIO pin that the button is connected to
    bool _pullupMode; // bool to determine if the button is in pullup mode (true) or pulldown mode (false) 
    bool _currentState; // The current state of the button (pressed or not pressed)
    bool _lastState;  // The last state of the button (pressed or not pressed)
    bool _toggleState;  // The toggle state of the button (on/off switch)
    
  public: // The public section contains variables and methods that ARE accessible outside the class.
  
    // CONSTRUCTOR_START
    Button(uint8_t pin, int mode) //  Constructor to initialized the button with a pin and mode
    {
      _pin = pin; // Assign the given pin number to the private variable _pin

      // set pullupMode based on the mode parameter
      if (mode == INPUT_PULLUP)
      {
        _pullupMode = true; //set pullup mode to true if mode is INPUT_PULLUP
      } 
      else if (mode == INPUT_PULLDOWN) 
      {
        _pullupMode = false;  //set pullup mode to false if mode is INPUT_PULLDOWN
      } 
      else if (mode == INPUT) //set no pullup mode if mode is INPUT
      {
        _pullupMode = false; //set pullup mode to false if mode is INPUT
      } 
      else if (mode == INPUT_PULLDOWN) //set no pullup mode if mode is INPUT_PULLDOWN
      {
        _pullupMode = false; //set pullup mode to false if mode is INPUT
      } 
      else 
      {
        _pullupMode = true; //default to pullup mode if neither INPUT_PULLUP nor INPUT_PULLDOWN is specified
      }

      pinMode(_pin, mode);  // Configure the pin with the specified mode
      
      // Start with all states at false (not pressed, toggle off)
      _currentState = false;
      _lastState = false;
      _toggleState = false;
    }
    // CONSTRUCTOR_END
    
    // Update button state - IMPORTANT: call this in LOOP
    void update() 
    {
      // Read the current state of the pin
      bool reading = digitalRead(_pin);
      
      // Save previous state
      _lastState = _currentState;
      
      // store button state based on pullup/pulldown mode
      if (_pullupMode) 
      {
        // For pullup: When button is pressed, reading is LOW (0), so we need to flip the value with NOT (!) operator
        _currentState = !reading;
      } 
      else 
      {
        // For pulldown: When button is pressed, reading is HIGH (1)
        _currentState = reading;
      }
      
      // flip the toggle state if button was just pressed (rising edge occurred)
      if (risingEdge()) 
      {
        if (_toggleState == true) 
        {
          _toggleState = false;
        } 
        else 
        {
          _toggleState = true;
        }
      }
    }
    
    // Returns true if button is currently being pressed
    bool pressed() 
    {
      return _currentState;
    }
    
    // Returns the current toggle state (on/off switch)
    bool toggle() 
    {
      return _toggleState;
    }
    
    // Manually set the toggle state. Useful for forcing the toggle to a specific state
    void setToggle(bool state) 
    {
      _toggleState = state;
    }
    
    // Rising edge: button was just PRESSED
    bool risingEdge() 
    {
      //return TRUE if current state is pressed (true) AND last state was not pressed (false)
      return (_currentState == true && _lastState == false);
    }
    
    // Falling edge: button was just RELEASED
    bool fallingEdge() 
    {
      //return TRUE if current state is NOT pressed (false) AND last state was pressed (true)
      return (_currentState == false && _lastState == true);
    }
};

#endif  
// #endif is used to close the #ifndef statement at the top, part of the header guard.
// This prevents the file from being included multiple times, which could cause errors.