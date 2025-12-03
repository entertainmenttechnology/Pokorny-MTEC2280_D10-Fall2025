/*
 "SERIAL MULTITOUCH SENSOR"

 - to be used with Arduino MultiTouch example

 - Receives a byte via Serial UART
 - incoming Byte is composed of 8 touch points ON/OFF bits from MicroController
 - Incoming byte is compared using BITWISE AND (&), which returns true when all bits match
 - EXAMPLE: (0b0001 & 0b0001) would return true, (0b0001 & 0b0011) would return false
*/


let serial; // declare variable for an instance of the serialport library
let portName = '/dev/tty.usbserial-213320';  // fill in your serial port name here
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code

let inByte; // declare variable for storing incoming serial data
let xPos = 10;
let rate = 1;
let diameter = 100;

//BYTE MASKS used to compare incoming byte value
const mask_1  = 0b00000001;
const mask_2  = 0b00000011;
const mask_3  = 0b00000010;
const mask_4  = 0b00000110;
const mask_5  = 0b00000100;
const mask_6  = 0b00001100;
const mask_7  = 0b00001000;
const mask_8  = 0b00011000;
const mask_9  = 0b00010000;
const mask_10 = 0b00110000;
const mask_11 = 0b00100000;
const mask_12 = 0b01100000;
const mask_13 = 0b01000000;
const mask_14 = 0b11000000;
const mask_15 = 0b10000000;

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
  background(0, 32);

  //by using BITWISE AND (&), we can check if our inByte matches the mask's binary pattern
  if (inByte & mask_1)
  {
    rate = -4.5;
  }
  else if (inByte & mask_2)
  {
    rate = -4;
  }
  else if (inByte & mask_3)
  {
    rate = -3.5;
  }
  else if (inByte & mask_4)
  {
    rate = -3;
  }
  else if (inByte & mask_5)
  {
    rate = -2.5;
  }
  else if (inByte & mask_6)
  {
    rate = -2;
  }
  else if (inByte & mask_7)
  {
    rate = -1.5;
  }
  else if (inByte & mask_8)
  {
    rate = 1;
  }
  else if (inByte & mask_9)
  {
    rate = 1.5;
  } 
  else if (inByte & mask_10)
  {
    rate = 2;
  }
  else if (inByte & mask_11)
  {
    rate = 2.5;
  }
  else if (inByte & mask_12)
  {
    rate = 3;
  }
  else if (inByte & mask_13)
  {
    rate = 3.5;
  }
  else if (inByte & mask_14)
  {
    rate = 4;
  }
  else if (inByte & mask_15)
  {
    rate = 4.5;
  }
  else
  {
    rate = 0;
  }

  xPos += rate; //adjust xPos based on rate of movement
  
  //draw on other side of screen if circle goes off screen
  if (xPos > width + diameter/2)
  {
    xPos = -diameter/2; 
  }

  if (xPos < -diameter/2)
  {
    xPos = width + diameter/2;
  }

  //draw circle and lines to canvas
  circle(xPos, height/2, 100);
  line(xPos, height/2, 0, height);
  line(xPos, height/2, width, height);
  line(xPos, height/2, width/2, height);
}

function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}
 
function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}
 
function serialEvent() //gets called when new data arrives
{
  inByte = Number(serial.read()); //Store incoming data as a number
  //print(inData);
}
 
function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}
 
function portClose() //gets called when the serial port closes
{
  print("*____SERIAL PORT CLOSED");
}
