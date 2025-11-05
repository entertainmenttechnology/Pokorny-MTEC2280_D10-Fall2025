/*
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||               "Serial Read - PIEZO"                    ||
||  Reads from Serial UART one ASCII character at a time  ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

- Receives data over Serial UART port from P5 sketch
- Compares incoming ASCII characters to play different notes on piezo buzzer
- Hook up Piezo Buzzer to pin 1 for this example

NOTE: We are using the ESP LED Control (LEDC) API on the ESP32S3 to generate our tone.
You can read more here:
https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/read/
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/available/
*/

const int pinRGB = 38;      // Built-in RGB LED pin
const int piezoPin = 1;     // Piezo buzzer pin
const int ledc_channel = 0; // LEDC channel (0 is default)
const int bitDepth = 12;    // Bit depth for LEDC

int freqs[] = {0, 220, 330, 440, 660, 880}; //array of frequencies, or pitches, for notes
int inByte = 0;         //variable for storing our incoming ASCII character
int note = 0;           //currently selected note in our freqs array
int currentTime = 0;    //variable to store current millis
int lastTime = 0;       //variable to store millis at moment of last event
int timerInterval = 50; //amount of milliseconds for comparison
int brightness = 8;     //LED brightness, max is 255, which is very bright!

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
    ledcWriteTone(piezoPin, freqs[note]); //generate PWM tone on piezo pin at given frequency
  }
  
  if(Serial.available())  //if there is data available in the serial buffer
  {
    inByte = Serial.read(); //read and store that received byte
  }

  // IF/ELSE statement for mapping ASCII Letters to notes and LED colors
  if (inByte == 'a' || inByte =='A')  //if 'a' or 'A' received...
  {
    rgbLedWrite(pinRGB, brightness, 0, 0);  // Red
    note = 1; //select element 1 of freqs array
  }
  else if (inByte == 's' || inByte == 'S')
  {
    rgbLedWrite(pinRGB, 0, brightness, 0);  // Green
    note = 2;
  }
  else if (inByte == 'd' || inByte == 'D')
  {
    rgbLedWrite(pinRGB, 0, 0, brightness);  // Blue
    note = 3;
  }
  else if (inByte == 'f' || inByte == 'F')
  {
    rgbLedWrite(pinRGB, brightness, brightness, 0);  // Yellow
    note = 4;
  }
  else if (inByte == 'g' || inByte == 'G')
  {
    rgbLedWrite(pinRGB, brightness, 0, brightness);  // Magenta
    note = 5;
  }
  else // default case
  {
    rgbLedWrite(pinRGB, 0, 0, 0); // LED OFF
    note = 0; // note 0 has a frequency of 0Hz, so PWM tone will turn off
  }
}
