/*
Button Counter
- Increment by one every time the button is pressed.
- Will not increment while held, thanks to Rising Edge Detection
*/

const int buttonPin = 9;

bool buttonState = 0;
bool lastButtonState = 0;

int counter = 0;
int maxCount = 10;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(115200);

}

void loop() {
  
  buttonState = !digitalRead(buttonPin);

  //RISING EDGE DETECTION
  //Detects the PRESS of a button
  if (buttonState && !lastButtonState) //if button went from LOW to HIGH
  {
    counter++;  //increment counter
  }

  if (counter > maxCount) //if counter is greater than maximum count variable...
  {
    counter = 0;  //reset counter
  }

  lastButtonState = buttonState;  //store current button state for logic comparison

  Serial.printf("Button = %i ; Count = %i \n", buttonState, counter);
}
