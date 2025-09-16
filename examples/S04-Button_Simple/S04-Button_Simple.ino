/*
//////////////////////////
//  PUSHBUTTON - SIMPLE //
//////////////////////////
- Reads HIGH/LOW on GPIO pin using digitalRead function.
- Connect one side of pushbutton to 3V3 and the other to buttonPin
- NOTE: this example requires external pullup or pulldown, or readings may be inaccurate!
REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
- https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalread/
*/


const int buttonPin = 9;  //GPIO we will read for High/Low Voltage

void setup() {
  pinMode(buttonPin, INPUT);  //set GPIO 9 to input
  
  Serial.begin(115200); //start serial comms
}

void loop() {
  bool buttonState = digitalRead(buttonPin);  //create a boolean and store current state of button

  Serial.println(buttonState);  //print state of button
}
