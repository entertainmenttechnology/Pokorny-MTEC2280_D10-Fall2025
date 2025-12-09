/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
////////////////////////////////////
//      "MULTI-TOUCH READ"        //
//    Capacitive Touch Sensing    //
//      by Ian Pokorny            //
////////////////////////////////////
- The ESP32 has capacitive touch sensing abilities on any pin labelled TOUCH
- simply use touchRead(pin) to read current value.
- using multiple touch points in different physical layouts can create "analog-like" behavior, like a pot or slider

REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/math/map/
- https://docs.espressif.com/projects/arduino-esp32/en/latest/api/touch.html
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

const int touchPin_1 = 4;  //can use any pin labelled TOUCH on ESP32
const int touchPin_2 = 5;
const int touchPin_3 = 6;
const int touchPin_4 = 7;
const int touchPin_5 = 9; 
const int touchPin_6 = 10;
const int touchPin_7 = 11;
const int touchPin_8 = 12;

int touchThreshold = 50000; //set this value based on measured touch threshold, adjust as needed

bool b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0;  //touch "button" booleans

void setup() 
{
  Serial.begin(9600);
}

bool touchGate(int tVal, int tThresh) //function for checking if touchRead is over threshold
{
  if (tVal > tThresh)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

void loop() 
{
  //read capacitive touch values
  int touchVal_1 = touchRead(touchPin_1); 
  int touchVal_2 = touchRead(touchPin_2); 
  int touchVal_3 = touchRead(touchPin_3); 
  int touchVal_4 = touchRead(touchPin_4); 
  int touchVal_5 = touchRead(touchPin_5); 
  int touchVal_6 = touchRead(touchPin_6); 
  int touchVal_7 = touchRead(touchPin_7); 
  int touchVal_8 = touchRead(touchPin_8); 

  //check if touch point is being pressed (over threshold)
  b1 = touchGate(touchVal_1, touchThreshold); 
  b2 = touchGate(touchVal_2, touchThreshold);
  b3 = touchGate(touchVal_3, touchThreshold);
  b4 = touchGate(touchVal_4, touchThreshold);
  b5 = touchGate(touchVal_5, touchThreshold);
  b6 = touchGate(touchVal_6, touchThreshold);
  b7 = touchGate(touchVal_7, touchThreshold);
  b8 = touchGate(touchVal_8, touchThreshold);

  //bit shift each button boolean into position inside of touchByte
  int touchByte = b1 | (b2 << 1) | (b3 << 2) | (b4 << 3) | (b5 << 4) | (b6 << 5) | (b7 << 6) | (b8 << 7);

  Serial.write(touchByte);  //send touchByte across Serial port 

  //Serial.println(touchByte, BIN); //uncomment to check byte status on arduino serial monitor
}

