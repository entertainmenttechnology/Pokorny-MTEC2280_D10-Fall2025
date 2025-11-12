## SESSION 10

REMEMBER to add the p5.serialport library to the index.html file of your p5.js projects:

```html
<script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>
```

## SHORT SKETCH #6: DUE 11/19

Create a software p5.js sketch and arduino sketch that implements serial handshaking (call & response). You may use any combination of sensors and actuators, but they should be controlled (or control) via serial. This assignment is more open-ended, as we have now learned to communicate in both directions in the same project! The content and approach are completely up to you, but it needs to implement serial handshaking.    
The short study must include:
- use of at least 2 hardware actuators controlled by interaction with your P5 sketch,  
    or at least 2 sensors controlling some aspect of your P5 sketch.
- at least 2 different modes of behavior: for example, our "P5_Serial_Servo" sketch has a "sweep" mode and a "follow" mode. 
- at least three graphics primitives.
- dynamic elements in your P5 sketch (don't just draw a static canvas, animate something!).
- display window width: max of 1080, min of 400
- display window height: max of 720, min of 400
           

Upload your completed code (both arduino & p5.js) to your repo before the beginnning of next class session.   
Remember, the arduino .ino file must go in folder of same name, and the p5.js project must include its entire project folder and it contents.   
Have your project (both hardware and software aspects) ready to present at the next class critique.

### Familiarize yourself with:

* [Arduino: Serial.read()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/read/)

* [Arduino: Serial.available()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/available/)

* [Arduino: Serial.parseInt()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/parseInt/)

* Arduino: the difference between [Serial.print()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/print/) and [Serial.write()](https://docs.arduino.cc/language-reference/en/functions/communication/serial/write/)

* [ASCII Table and Converter](https://www.rapidtables.com/convert/number/ascii-hex-bin-dec-converter.html)

* [P5: Math Functions](https://p5js.org/reference/#Math)
