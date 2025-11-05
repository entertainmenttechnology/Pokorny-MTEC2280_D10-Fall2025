/*
P5.JS SERIAL SEND LEDS

An example p5.js sketch that uses the p5.serialport library to send data across serial port one byte at a time.
Turn ON/OFF 2 LEDs on microcontroller by clicking mouse on the rectangular areas.

This code is designed to work with the "Arduino_Serial_Read_LEDs" example sketch.

NOTES:
- You must run and establish a serial connection with p5.serialcontrol app to use this code:
  https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2

- Remember to add the p5.serialport library to your index.html file. Add this line below <script src="libraries/p5.min.js"></script>:

    <script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>

- Make sure the baud rate in options matches the baud rate in your Arduino code.
- Remember to change the portName variable to match your own serial port.
*/



let serial; // variable for instance of the serialport library
let portName = '/dev/tty.usbserial-213320'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code
let outByte = 0;  // 8-bit data to send to microcontroller

function setup() 
{
  createCanvas(800, 400);
  textAlign(CENTER, CENTER);
  textSize(36);
  noStroke();

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
  background(220); // clear frame with background color

  //draw rectangular areas
  fill(200);
  rect(0, width/2, width, height/2);
  fill(255, 255, 0);
  rect(0, 0, width/2, height/2);
  fill(0, 255, 0);
  rect(width/2, 0, width/2, height/2);

  //display text
  fill(0);
  text ("THIS LED", width/4, height/4);
  text ("THAT LED", width-width/4, height/4);
  text ("NO LED", width/2, height-height/4);
}

function mousePressed() 
{
  //check mouse position when mouse is clicked
  if (mouseY > height/2 && mouseY < height) // bottom half of the canvas
  {
    outByte = 0;
  }
  else if (mouseX < width/2 && mouseX > 0 && mouseY < height/2) // top left quadrant
  {
    outByte = 1;
  }
  else if (mouseX > width/2 && mouseX < width && mouseY < height/2) // top right quadrant
  {
    outByte = 2;
  }
  else  // default case
  {
    outByte = 0;
  }

  serial.write(outByte); //send outByte across serial port
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
  //only sending data to microcontroller in this sketch, so not being used
}

function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}