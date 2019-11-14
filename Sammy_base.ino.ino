 // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value

#include <Wire.h>
#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMS = Adafruit_MotorShield();
//m1 - 1, m2 - 2, m3 - 3, m4 - 4
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(3);
 char val; // Data received from the serial port
 int ledPin = 4; // Set the pin to digital I/O 4
 
 void setup() {
 Serial.begin(9600); // Start serial communication at 9600 bps
 Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();

  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  LeftMotor->run(RELEASE);
  RightMotor->setSpeed(150);
  RightMotor->run(FORWARD);
  RightMotor->run(RELEASE);
 }
 
 void loop() {
  uint8_t i; 
 while (Serial.available()) { // If data is available to read,
 val = Serial.read(); // read it and store it in val
 }
// Serial.println(val);
 if (val == 'f') { // If f was received
    LeftMotor->run(FORWARD);
    LeftMotor->setSpeed(150);
    RightMotor->run(BACKWARD); //power and ground are opposite thats why it is the opposite direction
    RightMotor->setSpeed(150);
    
 } else if(val == 'l'){
    LeftMotor->run(BACKWARD);
    LeftMotor->setSpeed(150);
    RightMotor->run(BACKWARD);
    RightMotor->setSpeed(150); // Going to the left
 }
 else if(val == 'r'){
    LeftMotor->run(FORWARD);
    LeftMotor->setSpeed(150);
    RightMotor->run(FORWARD);
    RightMotor->setSpeed(150);
 }

 else if(val == 'b'){
    LeftMotor->run(BACKWARD);
    LeftMotor->setSpeed(150);
    RightMotor->run(FORWARD); //power and ground are opposite thats why it is the opposite direction
    RightMotor->setSpeed(150);
 }
  delay(100); // Wait 100 milliseconds for next reading
 }

 
 
