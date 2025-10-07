/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
////////////////////////////////////
//      "TOUCH READ"              //
//    Capacitive Touch Sensing    //
//      by Ian Pokorny            //
////////////////////////////////////
- The ESP32 has capacitive touch sensing abilities on any pin labelled TOUCH
- simply use touchRead(pin) to read current value.

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/math/map/
- https://docs.espressif.com/projects/arduino-esp32/en/latest/api/touch.html
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

const int touchPin = 11;  //can use any pin labelled TOUCH on ESP32
const int ledPin = 4;

int touchThreshold = 50000; //set this value based on measured touch threshold, adjust as needed

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  int touchVal = touchRead(touchPin); //read capacitive touch value

  if (touchVal > touchThreshold)  //if touchVal goes above threshold...
  {
    digitalWrite(ledPin, 1);    //turn on LED
  }
  else
  {
    digitalWrite(ledPin, 0);    //turn off LED
  }

  //adjust map values based on read input and desired output
  //map(input value, input low, input high, output low, output high)
  int mapVal = map(touchVal, 31110, 170000, 0, 1000);

  Serial.printf("Touch Read = %i \t Touch Mapped = %i \n", touchVal, mapVal);
}
