/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||||||
  ||       "LED PWM DIMMING"    ||
  ||       by Ian Pokorny       ||
  ||         MTEC-2280          ||
||||||||||||||||||||||||||||||||||||
- Simple demo of using analogWrite to dim an LED.
    - Connect LED circuit to GPIO Pin 4
    - NOTE: Don't forget your current-limiting resistor!

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

const int ledPin = 4;
int ms = 300; //adjust to speed up/slow down

void setup() {
  //don't need anything in setup to use PWM with analogWrite
}

void loop() {

  analogWrite(ledPin, 255); //send PWM signal @ 255 = FULL ON

  delay(ms);

  analogWrite(ledPin, 200); //send PWM signal @ 200

  delay(ms);

  analogWrite(ledPin, 127); //send PWM signal @ 127 = HALF brightness

  delay(ms);

  analogWrite(ledPin, 64);  //send PWM signal @ 64

  delay(ms);

  analogWrite(ledPin, 32);  //send PWM signal @ 32

  delay(ms);

  analogWrite(ledPin, 16);  //send PWM signal @ 16

  delay(ms);

  analogWrite(ledPin, 0);   //send PWM signal @ 0 = OFF

  delay(ms);
}
