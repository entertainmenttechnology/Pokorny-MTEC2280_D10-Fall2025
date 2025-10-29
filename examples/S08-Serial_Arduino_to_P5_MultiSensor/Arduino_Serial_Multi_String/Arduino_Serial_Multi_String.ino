/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||||||||||||||
||    "Multiple Sensors to Processing"    ||
||          "String Version"              ||
||||||||||||||||||||||||||||||||||||||||||||     
- Example of sending a String of Comma Separated Values via Serial UART.
- We are using the ASCII character '/n', aka "New Line", aka "Line Feed" to signal end of transmitted message. 
- Data is sent via Serial.print() INSTEAD of Serial.write(), as we did in the previous example.
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

//Define Pins
const int adcPin_1 = 1;
const int adcPin_2 = 2;
const int buttonPin_1 = 41;
const int buttonPin_2 = 42;

//Button Variables
bool buttonState_1 = 0;
bool buttonState_2 = 0;

//Pot Variables
int adcRead_1 = 0;
int adcRead_2 = 0;

//Software Timer Variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 5; //milliseconds

void setup() 
{
  //set button pin modes to Input with internal Pullup resistors
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  analogReadResolution(10); //set ADC read to 10-bit (0-1023) range
  Serial.begin(9600);  //start serial comm @ 9600 baud rate
}

void loop() 
{
  //read analog pot value
  adcRead_1 = analogRead(adcPin_1);
  adcRead_2 = analogRead(adcPin_2);
  //read button state on pins [NOTE: logic is inverted due to Pullup config]
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  currentTime = millis();                       //read current elapsed time
  if (currentTime - lastTime >= timerInterval)  //if we have reached our timer interval...
  {
    lastTime = currentTime;  //store current time as lastTime so we know when timer last triggered

    //Send Data to P5.JS Sketch via Serial UART using print() and Comma Separation
    Serial.print(buttonState_1);  //send 1st message
    Serial.print(',');            //send comma character
    Serial.print(buttonState_2);  //send 2nd message
    Serial.print(',');            //send comma character
    Serial.print(adcRead_1);      //send 3rd message
    Serial.print(',');            //send comma character
    Serial.print(adcRead_2);      //send 4th message
    Serial.print('\n');           //send "Line Feed", or "New Line" character, or use println() instead.
  }
}
