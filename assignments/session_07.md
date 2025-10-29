
## SESSION 07

## MIDTERM VERSION 2 DUE: 10/29
     
Based on feedback received during playtesting, do a 2nd iteration of your Midterm. Make sure you have included all the required elements from the assignment. Focus on debugging and user interface improvements rather than introducing new systems or elements.

See [MIDTERM](https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D10-Fall2025/blob/main/assignments/MIDTERM.md) for initial assignment details.

## SHORT SKETCH #3: DUE 11/05
Since we didn't finish covering serial communication from microcontroller to p5.js in class, this will be due in two weeks. I will repost in Session 08 assignments as well.

Use a single hardware analog sensor to control a software p5.js sketch. You may use either a photocell/LDR or Potentiometer as your sensor. The p5,js sketch must include:
- use of analog sensor data to control multiple elements of your P5 sketch. For example:
    - fill color, background color, shape size, shape location, etc.
- use of map() function
- use of declared variables
- use of background()
- use of fill()
- at least three graphics primitives
- display window width: max of 1080, min of 400
- display window height: max of 720, min of 400

Feel free to use images, sound library, etc. The content is completely up to you, but it needs to be controlled by Serial UART from Microcontroller.             

You may also use touchRead() as your analog sensor, though keep in mind that the range is considerably larger than 8-bit!

REMEMBER to add the p5.serialport library to the index.html file of your p5.js project:

```html
<script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>
```

### Familiarize yourself with:

* [P5.JS: Getting Started](https://p5js.org/tutorials/setting-up-your-environment/)    

* [P5.JS: Reference](https://p5js.org/reference/)

* [Arduino: UART Explained](https://docs.arduino.cc/learn/communication/uart/)

* [Arduino: Serial.write()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/write/)

* [Arduino: Serial.available()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/available/)

### Download & Install (if you have not already):

* [p5.serialcontrol](https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2)

* [Visual Studio CODE](https://code.visualstudio.com/download), not Visual Studio, and install the p5.js extension (instructions [here](https://p5js.org/tutorials/setting-up-your-environment/))

Upload your completed code (both arduino & p5.js) to your repo before the beginnning of next class session. Remember, the arduino .ino file must go in folder of same name, and the p5.js project must include its entire project folder and it contents.   
Have your project (both hardware and software aspects) ready to present at the next class critique.
