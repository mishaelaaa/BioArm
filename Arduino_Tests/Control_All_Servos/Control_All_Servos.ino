#include <Servo.h>

// create servo object to control a servo
Servo THUMB;
Servo INDEX;
Servo MIDDLE;
Servo RIGHT;
Servo PINKY;
Servo WRIST_RIGHT;
Servo WRIST_FRONT;

void setup() 
{
  THUMB.attach(3,600,2300);   // (pin, min, max)
  INDEX.attach(5,600,2300);   // (pin, min, max)
  MIDDLE.attach(6,600,2300);  // (pin, min, max)
  RIGHT.attach(9,600,2300);   // (pin, min, max)
  PINKY.attach(10,600,2300);  // (pin, min, max)
}

void loop() 
{
  THUMB.write(0);  // tell servo to go to a particular angle
  INDEX.write(0);  
  MIDDLE.write(0);  
  RIGHT.write(0);  
  PINKY.write(0); 
  delay(1000);
  
  THUMB.write(90);  
  INDEX.write(90);  
  MIDDLE.write(90);  
  RIGHT.write(90);  
  PINKY.write(90);            
  delay(500); 
  
  THUMB.write(130);  
  INDEX.write(130);  
  MIDDLE.write(130);  
  RIGHT.write(130);
  PINKY.write(130);             
  delay(500);
  /*
  THUMB.write(180);  
  INDEX.write(180);  
  MIDDLE.write(180);  
  RIGHT.write(180);
  PINKY.write(180);               
  delay(500);        
  */             
}
