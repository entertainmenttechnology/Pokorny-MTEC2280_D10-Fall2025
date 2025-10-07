/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
////////////////////////////////////
//      "ANALOG READ - MAPPED"    //
//    ADC w/ Rolling Average      //
//      by Ian Pokorny            //
////////////////////////////////////

ADC Reads can sometimes be noisy and jumpy...
- Let's implement two software approaches:
1. use analogReadResolution to reduce bit depth
2. implement a simple rolling average to filter (smooth) out read value

- The ESP32 does not have linear ADC response above 3V, so use circuit in schematic repo: "Potentiometer-Photocell"

- This example also shows use of map() function
- You can use an LDR in place of a potentiometer in this example

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/
- https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReadResolution/
- https://docs.arduino.cc/language-reference/en/functions/math/map/

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/
const int pinRGB = 38;    //built-in rgb led
const int potPin = 1;     //potentiometer pin

//adjust numReads to increase or reduce amount of smoothing, but beware of adding too much!
//try it and find out...
const int numReads = 16;  //number of readings in rolling average 
int reading[numReads];    //array of integers with length of numReads
int count = 0;            //counter to keep track of how many reads

void setup() 
{
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  analogReadResolution(11);   //reduce the ADC bit depth to 11-bit
}

void loop() 
{
  reading[count] = analogRead(potPin);  //store current ADC read in array at index of count
  count++;

  if (count >= numReads)  //if count is greater than or equal to number of reads...
  {
    count = 0;    //...reset count
  }

  int sum = 0;    //declare empty sum variable

  for (int i = 0; i < numReads; i++)  //for every reading in array...
  {
    sum += reading[i];  //add all the readings up and store in sum
  }

  int analogValue = sum / numReads; //calculate average reading and store in analogValue
  
  //map(input value, input low, input high, output low, output high)
  int mapVal = map(analogValue, 0, 1618, 0, 255);   //use map() to scale value to 0-255 range
  
  rgbLedWrite(pinRGB, mapVal, 0, 0);  //set built-in rgbLED red level

  Serial.printf("ADC raw = %i \t ADC averaged = %i \t ADC mapped = %i \n", analogRead(potPin), analogValue, mapVal); 
}
