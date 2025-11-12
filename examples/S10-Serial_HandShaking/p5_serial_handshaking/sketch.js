/*
P5.JS SERIAL HANDSHAKING EXAMPLE


An example p5.js sketch that uses the p5.serialport library to _____ across serial port.
Bidirectional Serial communication is established between P5.JS sketch and the ESP32 microcontroller.
Transmits(Tx) control bytes from P5 and Receives(Rx) sensor data from the microcontroller via Serial UART.
Click the Circle Button to Begin:
  - this will send a control byte of 'A' to the microcontroller to indicate that we want to receive data.
Click the Circle Button again to Pause/Start receiving data:
  - Pause will send a control byte of 'B' to the microcontroller to indicate that we want to pause receiving data.
  - Clicking the button when Paused will send 'A' to resume receiving data.

This code is designed to work with the "____" example sketch.

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

let rxFlag = false; // flag to indicate when new data has been received
let firstContact = false; // flag to indicate when the first contact has been made with the serial port
let sensors = [0, 0, 0, 0]; // declare array to hold incoming sensor data, and initialize with zeros
let pot1 = 0; // variable to hold potentiometer value
let pot2 = 0; // variable to hold potentiometer value
let button1 = 0; // variable to hold button value
let button2 = 0; // variable to hold button value


function setup() 
{
  //P5 Sketch Setup
  createCanvas(500, 500);
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
  background(0);
  stroke(127);

  if (!firstContact)  //if we have not yet received any data...
  {
  // display "Waiting" page
    background(0, 0, 127);
    fill(255);
    noStroke();
    text("Waiting for First Contact", width/2, height/4);
    text("Click Circle to Begin", width/2, height/3);
    circle(width/2, height/2, 140);
    fill(0);
    text("START RX", width/2, height/2);
  }
  else  //if we have established contact with the serial port, show main sketch...
  {
    //potentiometer indicator outlines
    fill(pot1);
    rect(width/8, height/4, 60, 255);
    fill(pot2);
    rect(width - width/4, height/4, 60, 255);

    //potentiometer indicators
    fill(0, pot1, 0);
    rect(width/8, height/4, 60, pot1);
    fill(pot2, 0, 0);
    rect(width - width/4, height/4, 60, pot2);

    //button indicators
    fill(button1);
    rect(width/2 - 100, height/4, 50, 50);
    fill(button2);
    rect(width/2 + 50, height/4, 50, 50);

    //pause button
    fill(200);
    circle(width/2, height/2, 140);

    if (rxFlag) // if rxFlag is true, we are receiving data, so...
    {
      fill(0);
      noStroke();
      text("PAUSE RX", width/2, height/2);  // display "PAUSE RX" on the button
    }
    else  //if rxFlag is false, we are not receiving data, so...
    {
      fill(255, 0, 0 );
      noStroke();
      text("PAUSED", width/2, height/2);  //display "PAUSED" on the button
    }
  }
}

function mousePressed() //if mouse is pressed...
{
  if (dist(mouseX, mouseY, width/2, height/2) < 70) // if mouse postion is within the radius of the circle button...
  {
    rxFlag = !rxFlag; // toggle the rxFlag

    if (rxFlag) //if rxFlag is true, we want to receive data, so...
    {
      serial.write('A'); // send 'A' to the serial port to indicate that we want to receive data
    }
    else  //if rxFlag is false, we want to pause receiving data, so...
    {
      serial.write('B'); // send 'B' to the serial port to indicate that we want to pause receiving data
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
  if (!firstContact)  //if we have not yet received any data, this is our first contact with the serial port, so...
  {
    print("FIRST CONTACT"); //print "FIRST CONTACT" to the console
    firstContact = true;  //set firstContact flag to true
  }
  
  if(rxFlag)  //if rxFlag is true, we want to receive data, so...
  {
    let inString = serial.readStringUntil('\n'); // read the incoming string until you get a newline character
    if (inString.length > 0) 
    {
      print("Rx String: " + inString); // print the incoming string to the console
      sensors = split(inString, ','); // split the string into an array of sensor values
    
      if(sensors.length >= 4) // check if we have all 4 sensor values before trying to access them
      {
        print(sensors); // print the array of sensor values to the console

        button1 = Number(sensors[0]); // convert the first sensor value to an integer
        button1 = map(button1, 0, 1, 0, 255); // map the button value from boolean true/false to 0-255

        button2 = Number(sensors[1]); // convert the second sensor value to an integer
        button2 = map(button2, 0, 1, 0, 255); // map the button value from boolean true/false to 0-255
        
        pot1 = Number(sensors[2]); // convert the third sensor value to an integer
        pot1 = map(pot1, 0, 1023, 0, 255); // map the potentiometer value from 0-1023 to 0-255
        pot1 = floor(pot1); // round the potentiometer value to an integer

        pot2 = Number(sensors[3]); // convert the fourth sensor value to an integer
        pot2 = map(pot2, 0, 1023, 0, 255); // map the potentiometer value from 0-1023 to 0-255
        pot2 = floor(pot2); // round the potentiometer value to an integer
        
        print("Button 1: " + button1 + " Button 2: " + button2 + " Pot 1: " + pot1 + " Pot 2: " + pot2);  //print mapped sensor values to the console

        //now that we're done processing the incoming data, we can "call out" to our microcontroller, which respond with latest sensor data.
        serial.write('A');  // send 'A' to the serial port to indicate that we want the latest sensor data
      }
    }
  }
  else
  {
    let inString = serial.readStringUntil('\n'); // read the incoming string until you get a newline character
    print(inString); // print the incoming string to the console
  }
}

function serialError(err) //gets called when there's an error
{
  print('SERIAL ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERIAL SERVER");
}