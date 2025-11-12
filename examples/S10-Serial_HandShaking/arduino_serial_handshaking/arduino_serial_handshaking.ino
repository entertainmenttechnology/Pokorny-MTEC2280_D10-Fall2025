/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
|||||||||||||||||||||||||||||||||||||||||||
||        "Serial HandShaking"           ||
||||||||||||||||||||||||||||||||||||||||||| 
  - Bi-Directional Serial Communication between Microcontroller & P5.JS
  - Tansmits(Tx) and Receives(Rx) Serial Data
  - Receives a control byte of either ASCII character 'A' or 'B'
  - Sends sensor data when 'A' byte received
  - Sends status message when 'B' byte received
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/
const int adcPin_1 = 1;
const int adcPin_2 = 2;
const int buttonPin_1 = 41;
const int buttonPin_2 = 42;
const int ledPin = 4;

bool buttonState_1 = 0;
bool buttonState_2 = 0;

int adcRead_1 = 0;
int adcRead_2 = 0;
int inByte = 0;

void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  analogReadResolution(10); //set ADC from 0 to 1023 range
  Serial.begin(9600); //open serial port at 9600bps
}

void loop()
{
  if(Serial.available()) //if serial buffer is greater than zero...
  {
    inByte = Serial.read(); //store incoming byte
    if(inByte == 'A') //if incoming byte is 'A'...
    {
      digitalWrite(ledPin, 1);  //turn LED ON
      adcRead_1 = analogRead(adcPin_1); //read pot 1
      adcRead_2 = analogRead(adcPin_2); //read pot 2
      buttonState_1 = !digitalRead(buttonPin_1);  //read button 1
      buttonState_2 = !digitalRead(buttonPin_2);  //read button 2
      Serial.print(buttonState_1);  //send 1st value
      Serial.print(',');            //send comma ASCII char to separate values
      Serial.print(buttonState_2);  //send 2nd value
      Serial.print(',');            //send comma ASCII char to separate values
      Serial.print(adcRead_1);      //send 3rd value
      Serial.print(',');            //send comma ASCII char to separate values
      Serial.print(adcRead_2);      //send 4th value
      Serial.print('\n');           //send newline ASCII char to frame end of message
    }
    else if (inByte == 'B') //if incoming byte is 'B'...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Sensor Update Paused...");  //send paused status message
      //using Serial.println adds a newline after each print, so no need for Serial.print('/n')
    }
    else //if incoming byte is neither 'A' nor 'B'...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Rx Byte is neither 'A' nor 'B'"); //send status message
    }
  }
}