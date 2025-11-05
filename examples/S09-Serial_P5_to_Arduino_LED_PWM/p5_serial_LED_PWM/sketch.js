/*
P5.JS SERIAL SEND LED PWM

An example p5.js sketch that uses the p5.serialport library to send data across serial port one byte at a time.
Sends 8-bit PWM values to dim LED on microcontroller. Mouse X position changes sent value.

This code is designed to work with the "Arduino_Serial_LED_PWM" example sketch.

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
  //____GFX_START____//
  //draw gradient background with for loop
  for (let i = 0; i < width; i++)
  {
    let c = map(i, 0, width, 0, 255);  //map i to 0-255 range for color
    stroke(c * 2, c, 0);    //change stroke color for each x position, red is scaled to 2x
    line(i, 0, i, height);  //draw vertical line for each x position
  }
  
  //display text
  fill(255);
  text ("DIMMER", width/4, height/2);
  fill(0);
  text ("BRIGHTER", width-width/4, height/2);
  
  //mouse position indicator
  fill(0, 0, 255, 127);
  circle(mouseX, mouseY, 20);
  //____GFX_END____//

  if(mouseY < height && mouseY > 0) //if mouseY is within canvas...
  {
    let posX = constrain(mouseX, 0, width); // constrain mouseX to canvas width, store as posX
    outByte = map(posX, 0, width, 0, 255); //remap posX to 0-255 range
    outByte = floor(outByte); // convert to integer, cut off decimal values
    serial.write(outByte);   //send byte across serial port
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