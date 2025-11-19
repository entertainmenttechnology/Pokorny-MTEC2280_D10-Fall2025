/*
P5.JS SERIAL BITSHIFTING EXAMPLE

An example p5.js sketch that uses the p5.serialport library to send LED PWM data and receive mode selection data across serial port.
Bidirectional Serial communication is established between P5.JS sketch and the ESP32 microcontroller.
Transmits(Tx) 16bit value from P5 and Receives(Rx) control byte from the microcontroller via Serial UART.

This code is designed to work with the "arduino_serial_bitshifting" example sketch.

NOTES:
- You must run and establish a serial connection with p5.serialcontrol app to use this code:
  https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2

- Remember to add the p5.serialport library to your index.html file. Add this line below <script src="libraries/p5.min.js"></script>:

    <script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>

- Make sure the baud rate in options matches the baud rate in your Arduino code.
- Remember to change the portName variable to match your own serial port.
*/

let serial; // variable for instance of the serialport library
let portName = '/dev/tty.usbserial-110'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code

let mode = 0;
let circleX = 0;
let circleY = 250;
let speedX = 5;
let speedY = 2;
let xPos = 0;
let lastTime = 0;
let currentTime = 0;
let interval = 300;

function setup() 
{
  //P5 Sketch Setup
  createCanvas(700, 500);
  textAlign(CENTER, CENTER);
  textSize(24);
  strokeWeight(4);
  stroke(127);

  //P5 SerialPort Setup
  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port
}

function draw() 
{
  if (mode == 0)
  {
    fill(0);
    noStroke();
    background(220);
    text("MODE 0: Mouse", width/6, height/8);
    text("mouseX sets LED 1 PWM, mouseY sets LED 2 PWM", width/2, height/2);

    let posX = constrain(mouseX, 0, width); // constrain mouseX to canvas width, store as posX
    posX = map(posX, 0, width, 0, 255); //remap posX to 0-255 range
    posX = floor(posX); // convert to integer, cut off decimal values

    let posY = constrain(mouseY, 0, height); // constrain mouseY to canvas height, store as posY
    posY = map(posY, 0, height, 0, 255); // remap posY to 0-255 range
    posY = floor(posY); // convert to integer, cut off decimal values

    let outByte = (posX << 8) | posY;  //shift posX 8 bits to the left and combine with posY using bitwise OR to create a single 16-bit value
    serial.write(outByte + '/n');   //send byte across serial port

    //for debugging: print the binary string representation of the output byte
    //let binaryString = outByte.toString(2);
    //print(binaryString);
  }
  else if (mode == 1)
  {
    background(0, 0, 255, 64);
    fill(255);
    noStroke();
    text("MODE 1: Circle", width/6, height/8);

    circle(circleX, circleY, 50);
    circleX += speedX;
    circleY += speedY;
    if (circleX > width)
    {
      speedX = random(-2, -10);
    }

    if (circleX < 0)
    {
      speedX = random(2, 10);
    }

    if (circleY > height)
    {
      speedY = random(-2, -10);
    }

    if (circleY < 0)
    {
      speedY = random(2, 10);
    }

    let pwm_1 = map(circleX, 0, width, 0, 255);
    let pwm_2 = map(circleY, 0, height, 0, 255);
    pwm_1 = constrain(pwm_1, 0, 255);
    pwm_2 = constrain(pwm_2, 0, 255);
    pwm_1 = floor(pwm_1);
    pwm_2 = floor(pwm_2);

    let outByte = (pwm_1 << 8) | pwm_2; //shift pwm_1 8 bits to the left and combine with pwm_2 using bitwise OR to create a single 16-bit value
    serial.write(outByte + '/n');   //send byte across serial port
  }
  else if (mode == 2)
  {
    noStroke();
    text("MODE 2: Perlin Noise", width/6, height/8);

    //read more on Perlin Noise here: https://p5js.org/reference/p5/noise/

    background(0, 255, 0, 3);
    let noiseLevel = 255;
    let noiseScale_1 = 0.04;

    // Scale the input coordinate.
    let nx = noiseScale_1 * xPos;

    // Compute the noise value.
    let y = noiseLevel * noise(nx);
    stroke(255, 0, 0);
    line(xPos, height, xPos, y);
    y = constrain(y, 0, 255);
    y = floor(y);
    y_2 = 255 - y;
    print(y_2);
    outByte = (y << 8) | y_2;
    serial.write(outByte + '/n');   //send byte across serial port

    xPos++;
    if (xPos >= width)
    {
      xPos = 0;
      background(0);
    }
  }
  else if (mode == 3)
  {
    //generate a random value between 0 and 255 every 300 milliseconds, and send it across the serial port
    currentTime = millis();
    if (currentTime - lastTime > interval) // check if 300 milliseconds have passed since the last update
    {
      let c = floor(random(0, 255));
      background(c, 255 - c, 127);
      noStroke();
      text("MODE 3: Random", width/6, height/8);
      lastTime = currentTime;
      let outByte = c << 8 | (255 - c) ;
      serial.write(outByte + '/n');   //send byte across serial port
    }
  }
}

function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}

function portClose() //gets called when the serial port closes
{
  print("SERIAL PORT CLOSED");
}

function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serialEvent() // gets called when new serial data arrives
{
  mode = Number(serial.read()); //store the incoming byte as a number in the variable "mode"
}

function serialError(err) //gets called when there's an error
{
  print('SERIAL ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERIAL SERVER");
}