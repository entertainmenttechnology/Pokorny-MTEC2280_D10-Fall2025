/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||||||
||  "SERIAL TEST - HELLO WORLD"   ||
||        by Ian Pokorny          ||
||          MTEC-2280             ||
||||||||||||||||||||||||||||||||||||
- A basic test of Serial Comms. between ESP32-S3 Dev Board & Serial Monitor
    - Connect USB cable to UART port of ESP32
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/

//This is a single line comment. Use comments to document your code
//Anything after "//" will not be seen by compiler
//To "comment out" a section of code, highlight section and press "CMD + /" [Mac] or "CTRL + /" [Win]

/* 
  - This is a multi-line comment
  - Anything within "slash asterisk" braces will be treated as comment
*/

//DECLARE GLOBAL VARIABLES HERE:
int loopCount = 0; //integer variable storing 
int ms = 500;   //integer variable storing delay amount

void setup() //setup() function runs only once at power on or if reset button pressed
{
  Serial.begin(115200); //start serial communication, accepts BAUD RATE as parameter

  //print message to serial monitor once setup code block is complete...
  Serial.println("<*>___SETUP COMPLETE___<*>"); 
}

void loop() //loop() function runs forever
{//start of loop() code block

  Serial.println("Hello World!");
  Serial.print("Loop Count = ");
  Serial.println(loopCount);

  //on our ESP32 board, you can also use Serial.prinf():
  //Serial.printf("Hello World! The loop count is now %d \n", loopCount);

  delay(ms); //wait specified amount of time before proceeding, in milliseconds

  loopCount++; //increment loopCount by 1
  //loopCount++ is the same as: loopCount = loopCount + 1;
  //loopCount++ is the same as: loopCount += 1;

  if (loopCount > 10) //if loopCount is greater than 10
  {
    loopCount = 0;  //reset loopCount to zero
    Serial.println("LOOP COUNT RESET");
  }

}//end of loop() code block
