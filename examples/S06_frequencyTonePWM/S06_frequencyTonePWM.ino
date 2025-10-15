/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||||||||||||
  ||       "MUSIC TO MY EARS"         ||
  ||      Generating Sound w/ PWM     ||
  ||       by Ian Pokorny             ||
  ||         MTEC-2280                ||
||||||||||||||||||||||||||||||||||||||||||
- Plays a looping melody with tone()
- uncomment lower portion, and comment out upper tone portion for experimental sounds

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/advanced-io/tone/

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

const int piezoPin = 21;
const int touchPin = 10;

void setup() 
{
  analogWriteResolution(piezoPin, 16);
  Serial.begin(115200);
}

void loop() 
{
  //tone(pin, frequency in Hz, duration in millisecond)
  tone(piezoPin, 220, 500);
  tone(piezoPin, 440, 1000);
  tone(piezoPin, 110, 200);
  tone(piezoPin, 200, 1000);
  tone(piezoPin, 200, 200);
  tone(piezoPin, 100, 200);


//PLUG IN A TOUCH POINT TO touchPin, & UNCOMMENT BELOW FOR SOMETHING WILDER!
  // int touchVal = touchRead(touchPin); //read capacitive touch value
  // int mapVal = map(touchVal, 27000, 170000, 300, 1000);
  // Serial.printf("TOUCH = %i \t MAP = %i \n", touchVal, mapVal);
  // analogWriteFrequency(piezoPin, mapVal);    //set PWM frequency
  // analogWrite(piezoPin, 127);                //write PWM @ set frequency
}