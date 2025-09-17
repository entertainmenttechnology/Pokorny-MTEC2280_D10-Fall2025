/*
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
////////////////////////////////////
//      "ANALOG READ"             //
//  ANALOG TO DIGITAL CONVERSION  //
////////////////////////////////////
- ADC capable pins of the MicroController can read analog voltage and convert into integer numbers
- NOTE: ADC Voltage range must be within 0-3.3V, otherwise you may damage device
- You can connect either of our analog sensors' outputs to potPin: 
    - Pot or Photocell [refer to schematic for wiring example]
REFERENCE:
- https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/
- https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReadResolution/
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
*/
const int potPin = 1;

void setup() 
{
  analogReadResolution(12);   //default ADC resolution for ESP32 is 12-bit [range of 0-4095]

  Serial.begin(115200); //start serial comms
}

void loop() 
{
  int adcVal = analogRead(potPin);  //read current analog voltage value @ potPin and store in variable

  Serial.println(adcVal); //print ADC value to serial monitor
}
