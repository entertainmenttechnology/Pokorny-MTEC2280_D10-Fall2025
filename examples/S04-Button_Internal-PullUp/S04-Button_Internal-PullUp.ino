/*
/////////////////////////////////////
//  PUSHBUTTON - INTERNAL PULLUP //
////////////////////////////////////
- Reads HIGH/LOW on GPIO pin using digitalRead function.
- Connect one side of pushbutton to GND and the other to buttonPin
_ internal pullup ensures there will either be a 1 or 0 reading, no indeterminate state
- with internal pullup, ON = 0, OFF = 1

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
- https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalread/
- https://www.arduino.cc/reference/cs/language/structure/boolean-operators/logicalnot/
*/


const int buttonPin1 = 45;
const int buttonPin2 = 10;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  Serial.begin(115200);

}

void loop() {
  //since we're using INPUT_PULLUP, pushbutton will read as 1 when OFF
  //if you want the logic to follow the standard ON = 1, OFF = 0...
  bool b1 = !digitalRead(buttonPin1); //...use LOGICAL NOT ! to flip the bit
  bool b2 = !digitalRead(buttonPin2);

  Serial.printf("Button 1 = %i | Button 2 = %i \n", b1, b2);
}
