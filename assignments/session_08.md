
## SESSION 08

REMEMBER to add the p5.serialport library to the index.html file of your p5.js projects:

```html
<script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>
```
## SHORT SKETCH #3: DUE 11/5

Use a single hardware analog sensor to control a software p5.js sketch. You may use either a photocell/LDR or Potentiometer as your sensor. The p5,js sketch must include:
- use of analog sensor data to control multiple elements of your Processing sketch. For example:
    - fill color, background color, shape size, shape location, etc.
- at least three graphics primitives
- display window width: max of 1080, min of 400
- display window height: max of 720, min of 400

Feel free to use images, sound library, etc. The content is completely up to you, but it needs to be controlled by Serial UART from your Microcontroller.             

You may also use touchRead() as your analog sensor, though keep in mind that the range is considerably larger than 8-bit!

## SHORT SKETCH #4: DUE 11/5
Use (at least) 4 hardware sensors to control a P5.JS sketch. You may use any combination of buttons, potentiometers, photocell, or touch points as your sensor. The Processing sketch must include:
- use of sensor data (transmitted via UART) to control multiple elements of your Processing sketch.
- use of map() function
- use of data type conversion
- use of declared variables
- use of background()
- use of fill()
- at least three graphics primitives
- display window width: max of 1080, min of 400
- display window height: max of 720, min of 400

Feel free to use images, sound library, etc. The content is completely up to you, but it needs to be controlled by Serial UART from Microcontroller.

### Familiarize yourself with:

* [Processing: Reference](https://processing.org/reference)

* [P5 SerialPort Library](https://processing.org/reference/libraries/serial/index.html) (check out METHODS on this page)

* [Arduino: Serial.print()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/print/)

* [Arduino: math functions such as constrain, abs, max, min](https://docs.arduino.cc/language-reference/#functions)

* [JavaScript: Data Type Conversions](https://www.w3schools.com/js/js_type_conversion.asp)

Upload your completed code (both arduino & processing) to your repo before the beginnning of next class session. 
Have your project (both hardware and software aspects) ready to present at the next class critique.

### Download & Install (if you have not already):

* [p5.serialcontrol](https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2)

* [Visual Studio CODE](https://code.visualstudio.com/download), not Visual Studio, and install the p5.js extension (instructions [here](https://p5js.org/tutorials/setting-up-your-environment/))

Upload your completed code (both arduino & p5.js) to your repo before the beginnning of next class session. Remember, the arduino .ino file must go in folder of same name, and the p5.js project must include its entire project folder and it contents.   
Have your project (both hardware and software aspects) ready to present at the next class critique.
