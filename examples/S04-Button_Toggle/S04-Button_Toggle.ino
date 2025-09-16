/*
/////////////////////////////////////
//      "EDGE DETECTION"          //
//  PUSHBUTTON AS TOGGLE SWITCH   //
////////////////////////////////////
- an example of Boolean Toggle using:
  - Rising Edge Detection
  - Falling Edge Detection
- we can use the momentary push button to create latching toggle logic
*/

const int buttonPin = 9;
const int ledPin = 4;

bool buttonState = 0;     //current button state
bool lastButtonState = 0; //previous button state
bool toggle = 0;          //toogle bool for rising edge
bool fallToggle = 0;      //toggle bool for falling edge

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  buttonState = !digitalRead(buttonPin);

  //RISING EDGE DETECTION
  //Detects the PRESS of a button
  if (buttonState && !lastButtonState) //if button went from LOW to HIGH
  {
    toggle = !toggle; //flip toggle bool using NOT logic
  }

  //FALLING EDGE DETECTION
  //Detects the RELEASE of a button
  if (!buttonState && lastButtonState) //if button went from HIGH to LOW
  {
    fallToggle = !fallToggle; //flip fallToggle bool using NOT logic
  }

  lastButtonState = buttonState;  //store current button state for logic comparison at beginning of next loop

  digitalWrite(ledPin, toggle);   //turn LED on & off with toggle

  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);
}
