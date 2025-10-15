/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||||||||||||
  ||   "LED PWM DIMMING: FOR LOOP"    ||
  ||       by Ian Pokorny             ||
  ||         MTEC-2280                ||
||||||||||||||||||||||||||||||||||||||||||
- Demo of using analogWrite & for loops to dim an LED off and on.
    - Connect LED circuit to GPIO Pin 4
    - NOTE: Don't forget your current-limiting resistor!

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/
- https://docs.arduino.cc/language-reference/en/structure/control-structure/for/
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

const int ledPin = 4;
int ms = 30; //adjust to speed up/slow down

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{

  for (int i = 0; i < 255; i++)  //starting from 0, incrementing to 255
  {
    analogWrite(ledPin, i); //send PWM signal @ current i value
    delay(ms);
    Serial.printf("FOR LOOP 1: %i \n",i);
  }

  for (int i = 255; i > 0; i--) //starting from 255, decrementing to 0
  {
    analogWrite(ledPin, i); //send PWM signal @ current i value
    delay(ms);
    Serial.printf("FOR LOOP 2: %i \n",i);
  }


   
}
