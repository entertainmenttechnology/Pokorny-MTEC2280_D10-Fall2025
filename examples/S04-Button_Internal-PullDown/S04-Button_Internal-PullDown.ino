/*
/////////////////////////////////////
//  PUSHBUTTON - INTERNAL PULLDOWN //
////////////////////////////////////
- Reads HIGH/LOW on GPIO pin using digitalRead function.
- Connect one side of pushbutton to 3V3 and the other to buttonPin
_ internal pulldown ensures there will either be a 1 or 0 reading, no indeterminate state
- with internal pulldown, ON = 1, OFF = 0
- not all Arduino-supported boards do this, so check Dev board docs!

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
- https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalread/
*/

const int buttonPin = 9;

void setup() {
  pinMode(buttonPin, INPUT_PULLDOWN); //set pin to input with internal pulldown resistor
  
  Serial.begin(115200);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  Serial.println(buttonState);
}
