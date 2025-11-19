/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
|||||||||||||||||||||||||||||||||||||||||||
||        "Serial to Max/MSP"           ||
||||||||||||||||||||||||||||||||||||||||||| 
  - Bi-Directional Serial Communication between Microcontroller & Max/MSP
  - Tansmits(Tx) and Receives(Rx) Serial Data
  - Receives a control byte of 255 
  - Sends sensor data when value of 255 received
  - Stops transmitting sensor data when any other value received
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

#define adcPin_1 1
#define adcPin_2 2
#define buttonPin_1 41
#define buttonPin_2 42
#define ledPin 4

bool buttonState_1 = 0;
bool buttonState_2 = 0;

int adcRead_1 = 0;
int adcRead_2 = 0;
int inByte = 0;

//Software Timer Variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 30;  //milliseconds

void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  analogReadResolution(10);  //set ADC from 0 to 1023 range
  Serial.begin(9600);        //open serial port at 9600bps
}

void loop() 
{
  if (Serial.available())  //if serial buffer is greater than zero...
  {
    inByte = Serial.read();  //store incoming byte
  }

  currentTime = millis();                       //read current elapsed time

  if (currentTime - lastTime >= timerInterval)  //if we have reached our timer interval...
  {
    lastTime = currentTime;  //store current time as lastTime so we know when timer last triggered

    if (inByte == 255) //if inByte is 255...
    {
      digitalWrite(ledPin, 1);                    //turn LED ON
      adcRead_1 = analogRead(adcPin_1);           //read pot 1
      adcRead_2 = analogRead(adcPin_2);           //read pot 2
      buttonState_1 = !digitalRead(buttonPin_1);  //read button 1
      buttonState_2 = !digitalRead(buttonPin_2);  //read button 2

      Serial.print(adcRead_1);      //send 1st value
      Serial.print(' ');            //send space ASCII char to separate values
      Serial.print(adcRead_2);      //send 2nd value
      Serial.print(' ');            //send space ASCII char to separate values
      Serial.print(buttonState_1);  //send 3rd value
      Serial.print(' ');            //send space ASCII char to separate values
      Serial.print(buttonState_2);  //send 4th value
      Serial.println();             //sends a carriage return (ASCII 13), then a newline char (ASCII 10)
    }
    else  //if inByte is any value other than 255...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
    }
  }
}