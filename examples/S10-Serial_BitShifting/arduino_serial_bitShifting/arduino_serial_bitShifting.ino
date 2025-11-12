/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
|||||||||||||||||||||||||||||||||||||||||||
||        "Serial BitShifting"           ||
||||||||||||||||||||||||||||||||||||||||||| 
  - Bi-Directional Serial Communication between Microcontroller & P5.JS
  - Tansmits(Tx) and Receives(Rx) Serial Data
  - Receives a combined 2-byte message as integer across Serial
  - Uses Bit Shifting to isolate the 2 bytes
  - Uses these bytes for LED PWM
  - Sets "mode" (on p5.js side) based on pot position

  FURTHER READING:
  https://docs.arduino.cc/language-reference/en/functions/communication/serial/parseInt/
  https://docs.arduino.cc/language-reference/en/structure/bitwise-operators/bitshiftRight/
  https://docs.arduino.cc/language-reference/en/structure/bitwise-operators/bitshiftLeft/
  https://docs.arduino.cc/language-reference/en/structure/bitwise-operators/bitwiseOr/
  https://docs.arduino.cc/language-reference/en/structure/bitwise-operators/bitwiseAnd/

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/
const uint8_t adcPin = 1;
const uint8_t ledPin_1 = 4;
const uint8_t ledPin_2 = 5;

void setup() 
{
  analogReadResolution(2); //set ADC from 0 to 3 range, we will using this to choose mode
  Serial.begin(9600); //open serial port at 9600bps
} 

void loop()
{
  uint8_t adcRead = analogRead(adcPin);

  if(Serial.available()) //if serial buffer is greater than zero...
  {
    int inData = Serial.parseInt(); //look for next integer in serial buffer
    uint8_t pwm_1 = inData >> 8;    //shift upper byte of message to lower byte and store
    uint8_t pwm_2 = inData;         //store lower byte of message

    analogWrite(ledPin_1, pwm_1); //use upper byte to dim LED 1
    analogWrite(ledPin_2, pwm_2); //use lower byte to dim LED 2
    
  }

  Serial.write(adcRead);  //send pot position to serial port
}