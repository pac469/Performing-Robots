# Final Project: Sammy

### Concept and Description of the Performance

Sammy intended to be a performance that explores human relationships with Robots. Through a short story, this performance 
attempts to make the public care about Sammy as if it was alive and feel that its relationships with the human characters 
are genuine. The short story consists of three characters(Sammy,Sammy's friend, and Sammy's romantic interest) and is divided
three acts. In the first act, using the song "You've got in friend in me" from Toy story in the background, the relationship 
between Sammy and Sammy's friend is established through showing both characters happily playing a game together. I found effective using 
Toy Story's song because Toy Story is one of the most famous stories that succesfully explores human attachment with objects and it
will create a nostalgic sensation in the public of a time when they develop attachment to a particular object.
In the second act, Sammy shows his spontaneity, desires and personality. Sammy falls in love at first sight and  try
to flirt with its romantic interest in a  naive and adorkable way. Sammy asks help from his friend to approach its
romantic interest and its frie  provide with objects that Sammy then brings to its Romantic Interest, hoping this 
causes a good impression. In the third act, Sammy shows that it is in conflic with itself. After some rejections, 
Sammy's Romantic Interest finally agrees to go out with him, but that means that he has to stop spending time with his friend. 
This causes that when Sammy is about to leave with its Romantic Interest, Sammy looks back at his friend. And that glance Sammy
and Sammy's friend share is opened to interpretation of the public. 

This performance beyond exploring human attachment also attempt to answer the question "what make us humans?". Sammy, in essence, is only cables,
wood, code, electricity. So, is it possible that the public perceive him as alive?. If public can relate with Sammy and care
about it, it is a sign that Sammy is perceived as alive. The strategy used to create this perceptio is that the animations 
and movement of Sammy are intended to portrayed desire, attachment, conflict and vulnerability. Which are intrinsic attributes
of human beings. 

### Description of Sammy
Sammy have two main attributes. It can move and it can show animations. Animations are made through two panels(its belly and mouth)
made with LED strips and two Neopixel Rings(Eyes). The movement is made with two DC motors capable to move, Up, Down, Left, and Right.
Sammy building process was divided in three stages. Stage 1 consisted of building the base out of wood and two the DC Motors and wheels. 
Stage 2 consisted of builidng the body and the arms. Body was made out of wood and it has the shape of a Cube with 30 X 30 cm dimensions
In the center of one of the faces an LED stips Panel was added and in other two faces,a plastic arm was also added. In the third Stage,
a carboard head was added at the top of the body cube. Two neopixels and another LED strip Panel was added to simulate eyes and mouth. 


### Overall Pictures 
##### Stage 1
*![Stage1](Stage1.png)
*![Arduino](Arudino.png)
*![Base](Base.png)
##### Stage 2
*![Stage2](Stage2.png)
*![Arm1](Arm1.png)
*![Arm2](Arm2.png)
*![Panel](Panel.png)
*![Heart](Heart.png)
##### Stage 3
*![Stage3] (Stage3.png)
*![Eyes] (Eyes.png)
*![Mouth] (Mouth.png)
##### Sammy Finshed
*![Sammy1](Sammy1.png)
*![Sammy2](Sammy2.png)
*![Sammy3](Sammy3.png)


### Important Parts
* 2 DC Motors
* 2 Wheels
* LED Strips
* 2 Neopixel Rings
* Motor Shield
* Arduino Uno

### Pictures of the Electronics
*![Motorshield](Motorshield.png)
*![Ledstrips](Ledstrips.png)
*![DC Motors](DCmotors.png)

### System Diagram Hardware
*![System Digram Hardware)(SDH.png)


### Code
##### Arduino 
```bash
      //Neoppixels
      #include <Adafruit_NeoPixel.h>
      #ifdef __AVR__
       #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
      #endif
      
      #define NUMPIXELS 179
      //#define EYEPIXELS 24
      #define LED_PIN 5
      
      //color Red = Color(255,51,51);
      Adafruit_NeoPixel pixels (NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
      
      //Adafruit_NeoPixel eye (EYEPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
      
      #define DELAYAL 500 // Time (in milliseconds) to pause between pixels
      
      // Declare our NeoPixel strip object:
      //Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
      //Neopixels done
      
      #include <Adafruit_MotorShield.h>
      #include <Wire.h>
      
      Adafruit_MotorShield AFMS = Adafruit_MotorShield();
      Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
      Adafruit_DCMotor *RightMotor = AFMS.getMotor(3);
      char val; // Data received from the serial port
      
      
   void setup(){
        Serial.begin(9600);  // Begin the serial monitor at 9600bps
        Serial.println("Adafruit Motorshield v2 - DC Motor test!");
        AFMS.begin();
        LeftMotor->setSpeed(150);
        LeftMotor->run(FORWARD);
        LeftMotor->run(RELEASE);
        RightMotor->setSpeed(150);
        RightMotor->run(FORWARD);
        RightMotor->run(RELEASE);
      
        //Neopixels Setup
        pixels.clear();
        pixels.begin();
        pixels.setBrightness(50);
      }
      
      
   void loop(){
        if(Serial.available() >0){ // If I am receiving values from Processing
        char input = Serial.read(); // Read values from Processing
          Serial.println(input);
          if (input == 'f') { // Move Forward
            Serial.println("Hello");
            LeftMotor->run(FORWARD);
            LeftMotor->setSpeed(150);
            RightMotor->run(BACKWARD); //power and ground are opposite thats why it is the opposite direction
            RightMotor->setSpeed(150);
            Normal_Animation(); // Display default animation 
          }
          else if (input == 'l') { // Move to the Left
            LeftMotor->run(BACKWARD);
            LeftMotor->setSpeed(150);
            RightMotor->run(BACKWARD);
            RightMotor->setSpeed(150); 
            Normal_Animation();// Display default animation 
          }
          else if (input == 'r') {
            LeftMotor->run(FORWARD);
            LeftMotor->setSpeed(150);
            RightMotor->run(FORWARD);
            RightMotor->setSpeed(150);
            Normal_Animation(); // Display default animation
          }
          else if (input == 'b') {
            LeftMotor->run(BACKWARD);
            LeftMotor->setSpeed(150);
            RightMotor->run(FORWARD); //power and ground are opposite thats why it is the opposite direction
            RightMotor->setSpeed(150);
            Normal_Animation();// Display default animation
          }
          else if(input == 'h'){ // Display In love Animation 
             inLove_Animation();
          }
          else if(input == 'n'){ // Display default Animation 
            Normal_Animation();
          }
          else if(input == 'e'){ // Display Excited Aniamtion 
            Excited_Animation();
          }
          else if(input == 's'){ // Display Sad Animation 
            Sad_Animation();
          }
        }
        }
      
      void eyes(){
        for(int i = 131;i<180;i++){
           pixels.setPixelColor(i, pixels.Color(102, 178,255)); // Display Neopixel Rings
          }
      }
      
      
      void heart(){ // Draw a heart
         pixels.clear();
         pixels.setPixelColor(107, pixels.Color(102, 178,255)); 
         pixels.setPixelColor(85, pixels.Color(102, 178,255)); 
         pixels.setPixelColor(79, pixels.Color(102, 178,255));
         pixels.setPixelColor(58, pixels.Color(102, 178,255));
         pixels.setPixelColor(50, pixels.Color(102, 178,255));
         pixels.setPixelColor(31, pixels.Color(102, 178,255));
         pixels.setPixelColor(21, pixels.Color(102, 178,255));
         pixels.setPixelColor(6, pixels.Color(102, 178,255));
         
         pixels.setPixelColor(8, pixels.Color(102, 178,255));
         pixels.setPixelColor(17, pixels.Color(102, 178,255));
         pixels.setPixelColor(36, pixels.Color(102, 178,255));
         pixels.setPixelColor(44, pixels.Color(102, 178,255));
         pixels.setPixelColor(65, pixels.Color(102, 178,255));
         pixels.setPixelColor(71, pixels.Color(102, 178,255));
         pixels.setPixelColor(94, pixels.Color(102, 178,255));
         pixels.setPixelColor(94, pixels.Color(102, 178,255));
         pixels.setPixelColor(99, pixels.Color(102, 178,255));
         pixels.setPixelColor(103, pixels.Color(102, 178,255));
         
         pixels.setPixelColor(7, pixels.Color(255, 0,0)); 
         
         pixels.setPixelColor(21-1, pixels.Color(255, 0,0)); 
         pixels.setPixelColor(20-1, pixels.Color(255, 0,0)); 
         pixels.setPixelColor(19-1, pixels.Color(255, 0,0));
       
         pixels.setPixelColor(33-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(34-1, pixels.Color(255, 0,0)); 
         pixels.setPixelColor(35-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(36-1, pixels.Color(255, 0,0)); 
         
         pixels.setPixelColor(50-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(49-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(48-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(47-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(46-1, pixels.Color(255, 0,0));
      
         pixels.setPixelColor(60-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(61-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(62-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(63-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(64-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(65-1, pixels.Color(255, 0,0));
        
         pixels.setPixelColor(79-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(78-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(77-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(76-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(75-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(74-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(73-1, pixels.Color(255, 0,0));
         
         pixels.setPixelColor(87-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(88-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(89-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(90-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(91-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(92-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(93-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(94-1, pixels.Color(255, 0,0));
      
         pixels.setPixelColor(107-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(106-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(105-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(103-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(102-1, pixels.Color(255, 0,0));
         pixels.setPixelColor(101-1, pixels.Color(255, 0,0));
         
        }
      
        void happy_face(){  // Draw a happy face 
          pixels.setPixelColor(112, pixels.Color(102, 178,255));
          pixels.setPixelColor(116, pixels.Color(102, 178,255));
      
          pixels.setPixelColor(122, pixels.Color(102, 178,255));
          pixels.setPixelColor(119, pixels.Color(102, 178,255));
      
          pixels.setPixelColor(127, pixels.Color(102, 178,255));
          pixels.setPixelColor(128, pixels.Color(102, 178,255));
          pixels.setPixelColor(129, pixels.Color(102, 178,255)); 
        }
      
        void sad_face(){ // Draw a sad face
          pixels.setPixelColor(113-1, pixels.Color(102, 178,255));
          pixels.setPixelColor(114-1, pixels.Color(102, 178,255));
          pixels.setPixelColor(115-1, pixels.Color(102, 178,255));
      
          pixels.setPixelColor(122-1, pixels.Color(102, 178,255));
          pixels.setPixelColor(119-1, pixels.Color(102, 178,255));
      
          pixels.setPixelColor(126-1, pixels.Color(102, 178,255));
          pixels.setPixelColor(130-1, pixels.Color(102, 178,255));
        }
      
        void Heartbreak(){ // Display a heartbroken
          for(int i = 0;i<111;i++){
            if( i!=21-1||i!=19-1 ||i!=33-1 ||i!=34-1|| i!=36-1 || i!=50 -1|| i!=49-1
             ||i!=47-1 ||i!=46 -1||i!=60 -1||i!=61 -1||i!=62 -1 ||i!=64-1 ||i!=65 -1||i!=79-1 ||
            i!=78-1  ||i!=75-1 ||i!=74-1 ||i!=87 -1||i!=88-1 ||i!=89-1 ||i!=90-1||
            i!=92-1 ||i!=93 -1||i!=94-1 ||i!=107-1 ||i!=106-1 ||i!=105-1 ||i!=103-1 ||i!=102 -1||i!=101-1)
            pixels.setPixelColor(i, pixels.Color(102, 178,255)); 
         
        }
      
        
          //pixels.setPixelColor(7, pixels.Color(255, 0,0)); 
         
          pixels.setPixelColor(21-1, pixels.Color(255, 0,0)); 
          //pixels.setPixelColor(20, pixels.Color(255, 0,0)); 
          pixels.setPixelColor(19-1, pixels.Color(255, 0,0));
       
          pixels.setPixelColor(33-1, pixels.Color(255, 0,0));
          pixels.setPixelColor(34-1, pixels.Color(255, 0,0)); 
          //pixels.setPixelColor(35, pixels.Color(255, 0,0));
          pixels.setPixelColor(36-1, pixels.Color(255, 0,0)); 
         
           pixels.setPixelColor(50-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(49-1, pixels.Color(255, 0,0));
           //pixels.setPixelColor(48, pixels.Color(255, 0,0));
           pixels.setPixelColor(47-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(46-1, pixels.Color(255, 0,0));
        
           pixels.setPixelColor(60-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(61-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(62-1, pixels.Color(255, 0,0));
           //pixels.setPixelColor(63, pixels.Color(255, 0,0));
           pixels.setPixelColor(64-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(65-1, pixels.Color(255, 0,0));
          
           pixels.setPixelColor(79-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(78-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(77-1, pixels.Color(255, 0,0));
           //pixels.setPixelColor(76, pixels.Color(255, 0,0));
           pixels.setPixelColor(75-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(74-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(73-1, pixels.Color(255, 0,0));
           
           pixels.setPixelColor(87-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(88-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(89-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(90-1, pixels.Color(255, 0,0));
           //pixels.setPixelColor(91, pixels.Color(255, 0,0));
           pixels.setPixelColor(92-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(93-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(94-1, pixels.Color(255, 0,0));
        
           pixels.setPixelColor(107-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(106-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(105-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(103-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(102-1, pixels.Color(255, 0,0));
           pixels.setPixelColor(101-1, pixels.Color(255, 0,0));
          }
      
        void Normal_Animation(){ // Functions that coordinates the normal Animation
          pixels.clear();
          for(int i = 0;i<111;i++){
            pixels.setPixelColor(i, pixels.Color(102, 178,255)); 
          }
          happy_face();
          eyes();  
          pixels.show();
        }
      
      
        void Sad_Animation(){ // Function that coordinates Sad Animation
          pixels.clear();
          sad_face();
          Heartbreak();
          eyes();
          pixels.show();
          
        }
      
        void inLove_Animation(){ // Functino that coordinates InLove Animation 
          pixels.clear();
          heart();
          happy_face();
          eyes();
          pixels.show();
        }
      
       void Excited_Animation(){ // Funcitino that Coordinates Excited_Animation
          pixels.clear();
          exciting();
          pixels.show();
         }
      
      void exciting(){ // Belly display when it is excited
        char reading ='e';
        for(int i =0 ; i<pixels.numPixels();i++){
          reading = Serial.read();
          pixels.setPixelColor(i, pixels.Color(255, 153,255));
       
          }
        }
        
  ```
  ##### Processing
  ##### Processing Main Code
  ``` Java
  import processing.serial.*;

Serial myPort;  // Create object from Serial class
char val;        // Data received from the serial port
Button HeartBeat; 
Button Excited;
Button Normal;
Button Sad; 
boolean IsHeartBeat;
boolean IsExcited;
boolean IsNormal;
boolean IsSad;

void setup() 
{ 
  size(640, 480);
  val = 'n';//val will be send to arduino
  HeartBeat = new Button("HeartBeat",'h', width/10, height/10, width/10, height/10); // create buttons
  Excited = new Button("Excited",'e', width*.8, height/10, width/10, height/10);
  Normal = new Button("Normal", 'n', width/10, height*.8, width/10, height/10);
  Sad = new Button("Sad", 's', width*.8, height*.8, width/10, height/10);
  IsHeartBeat = false;
  IsExcited = false;
  IsNormal = false;
  IsSad = false;
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  // printArray(Serial.list());
   String portName = Serial.list()[6]; // get the name of the port
   println(portName);
   myPort = new Serial(this, portName, 9600); // create a port 
}

void draw() {
  background(0);
  //Check if any of the keys are being pressed
  keyPressed(); 
  //display buttons and check if they are being pressed 
  HeartBeat.display();
  IsHeartBeat = HeartBeat.mouseClicked(); 
  Excited.display();
  IsExcited = Excited.mouseClicked();
  Normal.display();
  IsNormal = Normal.mouseClicked();
  Sad.display();
  IsSad = Sad.mouseClicked();
  
  // Changing the instruction that processing will send
  if(IsHeartBeat == true){
    val = 'h'; 
  }
  else if(IsExcited == true){
    val = 'e';
  }
  
  else if(IsNormal == true){
    val = 'n';
  }
  
  else if(IsSad == true){
    val = 's';
  }
  
  println(val);
  //Send the value to arduino
  myPort.write(val);
}

//Check if any of the keys is being pressed. 
void keyPressed(){
  if(keyCode == LEFT){
    val = 'l';
  }
  else if(keyCode == UP){
    val = 'f';
  }
  else if(keyCode == RIGHT){
    val = 'r';
  }
   else if(keyCode == DOWN){
     val = 'b';
   }
}
``` 

##### Processing classes 
``` bash
// Buttons to send commands to arduino
class Button{
  String Command;
  float x, y, w,h;
  char toArduino;
  
  Button(String command, char toarduino, float X, float Y, float W, float H){
    Command = command;
    toArduino = toarduino;
    x = X;
    y = Y; 
    w = W;
    h = H;
  }
  


    
 
  
  void display(){  
    //display a hoverif  I am on the button 
   if(mouseX>x && mouseX<x+w && mouseY>y && mouseY<y+h){
      //print("I am");
      pushStyle();
      stroke(178,255,202);
      fill(255,104,204);
      rect(x,y,w,h);
      popStyle();
      text(Command,x,y,w,h);
     // popStyle(); 
    }
    
    else{
    //displat button 
    pushStyle();
    noStroke();
    fill(255,104,204);
    rect(x,y,w,h);
    popStyle();
    text(Command,x,y,w,h);
  }
  
  }
  
  boolean mouseClicked(){
    //check if the button is being pressed
    if(mouseX>x && mouseX<x+w && mouseY>y && mouseY<y+h&& mousePressed){
      return true; 
  }
  else{
    return false;
  }
 
}

}
```



      
      
      
      
      
        






  





