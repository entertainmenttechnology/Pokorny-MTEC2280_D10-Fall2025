/*
|||||||||||||||||||||||||||||||||||||||||||||||||
||          "Serial Read - LED DIGITAL"        ||
||  Reads from Serial UART one byte at a time  ||
|||||||||||||||||||||||||||||||||||||||||||||||||

- Receives data over Serial UART port from P5 to turn 2 LEDS on/off
- Hook up LEDs to pins 4 and 5;

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/read/
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/available/
*/

const int LED1 = 4; // LED 1 pin
const int LED2 = 5; // LED 2 pin
byte val; // store byte received from serial port

void setup() 
{
  pinMode(LED1, OUTPUT); // set pin as output
  pinMode(LED2, OUTPUT); // set pin as output
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() 
{
  if (Serial.available()) // If data is available to read
  { 
    val = Serial.read(); // read it and store it in val
  }

  if (val == 0) 
  { // If 0 received
    digitalWrite(LED1, LOW); // LEDs 1 & 2 off
    digitalWrite(LED2, LOW);
  }
  else if (val == 1) 
  { // If 1 received
    digitalWrite(LED1, HIGH); // LED 1 on
    digitalWrite(LED2, LOW); // LED 2 off
  }
  else if (val == 2) 
  { // If 2 received
    digitalWrite(LED2, HIGH); // LED 2 on
    digitalWrite(LED1, LOW); // LED 1 off
  }
}
