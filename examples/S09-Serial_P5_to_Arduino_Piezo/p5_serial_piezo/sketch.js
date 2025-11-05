/*
P5.JS SERIAL SEND PIEZO BUZZER

An example p5.js sketch that uses the p5.serialport library to send data across serial port one byte at a time.
Sends one byte (8-bit) ASCII values to control frequency of piezo buzzer. 

This code is designed to work with the "Arduino_Serial_Piezo" example sketch.

NOTES:
- You must run and establish a serial connection with p5.serialcontrol app to use this code:
  https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2

- Remember to add the p5.serialport library to your index.html file. Add this line below <script src="libraries/p5.min.js"></script>:

    <script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>

- Make sure the baud rate in options matches the baud rate in your Arduino code.
- Remember to change the portName variable to match your own serial port.
*/

let serial;                                 // variable for instance of the serialport library
let portName = '/dev/tty.usbserial-213320'; // fill in your serial port name
let options = { baudRate: 9600};            // change the baud rate to match your Arduino code
let outByte = 0;                            // 8-bit data to send to microcontroller

function setup() 
{
  createCanvas(600, 600);
  strokeWeight(2);

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
  background(0, 16); //clear background with low alpha (a.k.a. opacity) for trailing effect

  if(keyIsDown(65)) //if A is pressed...
  {
    //draw red rectangle
    fill(255, 0, 0);      
    rect(0, 0, width/5, height);
  }
  else if(keyIsDown(83)) //if S is pressed...
  {
    //draw green rectangle
    fill(0, 255, 0);
    rect(width/5, 0, width/5, height);
  }
  else if(keyIsDown(68))  //if D is pressed...
  {
    //draw blue rectangle
    fill(0, 0, 255);
    rect(2 * (width/5), 0, width/5, height);
  }
  else if(keyIsDown(70)) //if F is pressed...
  {
    //draw yellow rectangle
    fill(255, 255, 0);
    rect(3 * (width/5), 0, width/5, height);
  }
  else if(keyIsDown(71)) //if G is pressed...
  {
    //draw magenta rectangle
    fill(255, 0, 255);
    rect(4 * (width/5), 0, width/5, height);
  }
}

function keyPressed() //when a key is pressed...
{
  print(key); //print the key to the console, only here for monitoring, not necessary
  serial.write(key); //send ASCII value of the key pressed via serial port
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