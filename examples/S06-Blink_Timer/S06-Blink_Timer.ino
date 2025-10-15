/*
<><><><><><><><><><><><><><><><>
||||||||||||||||||||||||||||||||
||    "BLINK WITHOUT DELAY"   ||
||      by Ian Pokorny        ||
||          MTEC2280          ||
||||||||||||||||||||||||||||||||
- A sketch to show implementation of a simple repeating software timer
- This is preferred over using delay() as this is non-blocking
- Other code can run while timer is running, unlike delay()
- We can now adjust our timer interval using a potentiometer with little to no delay in response
<><><><><><><><><><><><><><><><>
*/

const int ledPin = 4;
const int adcPin = 1;

bool ledState = 0;  //led ON/OFF state

int currentTime = 0;  //variable to store current millis
int lastTime = 0;     //variable to store millis at moment of last event
int timerInterval = 1000; //amount of milliseconds for comparison

void setup() 
{
  pinMode(ledPin, OUTPUT);
  analogReadResolution(10); //set ADC read to 0-1023 range
  Serial.begin(115200);

}

void loop() 
{
  currentTime = millis(); //store current time

  timerInterval = map(analogRead(adcPin), 0, 1023, 10, 1000); //map ADC read from 0-1023 to 10-1000
  
  //now that we are not using delay(), we don't have to wait a whole second for pot value to update!

  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime; //store current time as last time (this is when timer reached interval)
    ledState = !ledState; //flip LED state
    Serial.println("<><><><>____TIMER TRIGGERED!____<><><><>"); //print that timer is trig'ed
  }

  digitalWrite(ledPin, ledState);

  Serial.printf("LED STATE: %i \t Timer Interval = %i \n", ledState, timerInterval);
}
