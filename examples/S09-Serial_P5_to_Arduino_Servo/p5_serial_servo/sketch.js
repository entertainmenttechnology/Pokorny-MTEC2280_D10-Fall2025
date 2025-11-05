/*
P5.JS SERIAL SEND PIEZO BUZZER

An example p5.js sketch that uses the p5.serialport library to send data across serial port one byte at a time.
Sends one byte (8-bit) value to control angle of servo motor. 

This code is designed to work with the "Arduino_Serial_Servo" example sketch.

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

//button interface
let buttonWidth = 200;
let buttonHeight = 100;
let button = false;

function setup() 
{
  createCanvas(800, 800);
  textAlign(CENTER, CENTER);
  rectMode(CENTER);
  textSize(32);
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
//____GFX_START____
  background(0);  //clear frame
  //background gradient 1
  for (let i = 0; i < height/2; i++)
  {
    let c = map(i, 0, height/2, 0, 255);  //map to color range
    stroke(c);  //change stroke color for each y position
    line(0, i, width, i);
  }
  //background gradient 2
  for (let i = height; i > height/2; i--)
  {
    let c = map(i, height/2, height, 255, 0);  //map to color range, inverted
    stroke(c);  //change stroke color for each y position
    line(0, i, width, i);
  }
  //center line
  stroke(127);
  line(0, height/2, width, height/2);
  //button
  fill(64);
  rect (width/2, height/2, buttonWidth, buttonHeight);
  //text
  fill(255);
  text ("THIS WAY", width/2, 100);
  text ("THAT WAY", width/2, height-100);
  text ("CLICK HERE", width/2, height/2);
  //mouse position indicator
  fill(255, 0, 0);
  circle(mouseX, mouseY, 20);
  //____GFX_END____
  
  if (button == false)  // if mouse button not pressed
  {
    let posY = constrain(mouseY, 0, height);
    outByte = map(posY, 0, width, 0, 180); //remap mouseY to 0-180 angle range for servo
    outByte = floor(outByte); // floor() cuts off decimal for whole number integers
    serial.write(outByte); //send outByte across serial port
  }
}

function mousePressed() 
{
  if (mouseX > width/2 - buttonWidth/2 && mouseX < width/2 + buttonWidth/2 && mouseY > height/2 - buttonHeight/2 && mouseY < height/2 + buttonHeight/2) 
  { 
    button = true;     //set button state to true, so we don't send two conflicting pieces of data (see line 77)
    serial.write(255); //send value of 255 across Serial
  }
  button = false; //returns button state to false, since we are done sending data
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