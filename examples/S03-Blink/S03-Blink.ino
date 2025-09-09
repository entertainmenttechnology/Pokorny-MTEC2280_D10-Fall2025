/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||||||
  ||        "LED BLINK"         ||
  ||       by Ian Pokorny       ||
  ||         MTEC-2280          ||
||||||||||||||||||||||||||||||||||||
- Simple demo of using digitalWrite to turn an LED on/off.
    - Connect LED circuit to GPIO Pin 4
    - NOTE: Don't forget your current-limiting resistor!
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

//DECLARE GLOBAL VARIABLES UP HERE
const int ledPin = 4;   //constant integer set to LED pin #
int ms = 500;           //integer variable storing delay amount
bool ledState = 0;      //boolean [1-bit] variable storing ledState

void setup() //runs once at start-up [power on or reset button]
{    
  pinMode(ledPin, OUTPUT);  //set LED pin to output voltage

  Serial.begin(115200);
}

void loop() //loop function runs forever
{ //START OF LOOP

  digitalWrite(ledPin, HIGH); //set LED pin to HIGH, 3.3V
  delay(ms);  //wait 500 milliseconds
  digitalWrite(ledPin, LOW);  //set LED pin to LOW, 0V
  delay(ms);  //wait 500 milliseconds

  //works the same as...
  // digitalWrite(ledPin, 1); //set LED pin to 1, 3.3V
  // delay(ms);  //wait 500 milliseconds
  // digitalWrite(ledPin, 0);  //set LED pin to 0, 0V
  // delay(ms);  //wait 500 milliseconds

  //works the same as...
  // digitalWrite(ledPin, true); //set LED pin to true, 3.3V
  // delay(ms);  //wait 500 milliseconds
  // digitalWrite(ledPin, false);  //set LED pin to false, 0V
  // delay(ms);  //wait 500 milliseconds

  //works the same as...
  // ledState = !ledState; //flip the LED state [0 to 1] using NOT logic
  // Serial.println(ledState);
  // digitalWrite(ledPin, ledState);
  // delay(ms);
  // ledState = !ledState; //flip the LED state [1 to 0] using NOT logic
  // Serial.println(ledState);
  // digitalWrite(ledPin, ledState);
  // delay(ms);

} // END OF LOOP [will begin again from start of loop]
