/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||                  "Serial Read - STRING"                           ||
||  Reads String value from Serial UART to control Piezo Frequency   ||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

- Receives String Data over Serial UART port from P5 sketch
- Parses, or converts, the incoming String into integer which controls peizo's freqeuncy
- Hook up Piezo Buzzer to pin 1 for this example

NOTE: We are using the ESP LED Control (LEDC) API on the ESP32S3 to generate our tone.
You can read more here:
https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/read/
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/available/
*/

const int piezoPin = 1;     // Piezo buzzer pin
const int ledc_channel = 0; // LEDC channel (0 is default)
const int bitDepth = 12;    // Bit depth for LEDC

int inData = 0;         //variable for storing our incoming ASCII character
int currentTime = 0;    //variable to store current millis
int lastTime = 0;       //variable to store millis at moment of last event
int timerInterval = 50; //amount of milliseconds for comparison

void setup() 
{
  Serial.begin(9600); // Initialize serial communication at 9600 baud

  // Attach piezoPin to LEDC channel with base frequency 220Hz and bit depth
  ledcAttachChannel(piezoPin, 220, bitDepth, ledc_channel); 
  //ledcAttachChannel(pin, baseFrequency, bitDepth, channel)
}

void loop() 
{
  currentTime = millis();
  if (currentTime - lastTime >= timerInterval) //if we have reached our timer interval...
  {
    lastTime = currentTime;
    ledcWriteTone(piezoPin, inData); //generate PWM tone on piezo pin at given frequency
  }
  
  if(Serial.available())  //if there is data available in the serial buffer
  {
    inData = Serial.parseInt(); //read and store that received byte

  }
}
