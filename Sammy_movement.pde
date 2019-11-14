/**
 * Simple Write. 
 * 
 * Check if the mouse is over a rectangle and writes the status to the serial port. 
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[6];
  println(portName);
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  keyPressed(); 
}

void keyPressed(){
  if(keyCode == LEFT){
    myPort.write('l');
    fill(0);
    ellipse(width/2,height/2,50,50);
  }
  else if(keyCode == UP){
    myPort.write('f');
    fill(255,255,0);
    ellipse(width/2,height/2,50,50);
  }
  else if(keyCode == RIGHT){
    myPort.write('r');
    fill(100,255,0);
    ellipse(width/2,height/2,50,50);
  }
   else if(keyCode == DOWN){
     myPort.write('b');
    fill(100,48,246);
    ellipse(width/2,height/2,50,50);
   }
}


/*
  // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value
 
 char val; // Data received from the serial port
 int ledPin = 4; // Set the pin to digital I/O 4
 
 void setup() {
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
 while (Serial.available()) { // If data is available to read,
 val = Serial.read(); // read it and store it in val
 }
 if (val == 'H') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 } else {
 digitalWrite(ledPin, LOW); // Otherwise turn it OFF
 }
 delay(100); // Wait 100 milliseconds for next reading
 }
 
 */
 
 
