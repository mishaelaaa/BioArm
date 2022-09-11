#include <Servo.h>

#define BAUD_RATE 115200

// create servo object to control a servo
Servo THUMB;
Servo INDEX;
Servo MIDDLE;
Servo RIGHT;
Servo PINKY;
Servo WRIST_RIGHT;
Servo WRIST_FRONT;

int pos = 0;

void setup() 
{
  THUMB.attach(3,600,2300);   // (pin, min, max)
  INDEX.attach(5,600,2300);   // (pin, min, max)
  MIDDLE.attach(6,600,2300);  // (pin, min, max)
  RIGHT.attach(9,600,2300);   // (pin, min, max)
  PINKY.attach(10,600,2300);  // (pin, min, max)
/*
  //the pin for the servo control 
  // attaches the servo for the thumb on pin 3 to the servo object
  THUMB.attach(3);  
  // attaches the servo for the index on pin 5 to the servo object
  INDEX.attach(5);
  // attaches the servo for the middle on pin 6 to the servo object
  MIDDLE.attach(6);
  // attaches the servo for the right on pin 9 to the servo object
  RIGHT.attach(9);
  // attaches the servo for the pinky on pin 10 to the servo object
  PINKY.attach(10);
  */
}

void loop() 
{
  THUMB.write(0);  // tell servo to go to a particular angle
  INDEX.write(0);  
  MIDDLE.write(0);  
  RIGHT.write(0);  
  PINKY.write(0); 
  delay(1000);
  /*
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
*/
  THUMB.write(180);  
  INDEX.write(180);  
  MIDDLE.write(180);  
  RIGHT.write(180);
  PINKY.write(180);               
  delay(1000);    
  /*

  for (pos = 0; pos <= 180; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    THUMB.write(pos);   // tell servo 1 to go to position in variable 'pos'
    INDEX.write(pos);   // tell servo 2 to go to position in variable 'pos'
    MIDDLE.write(pos);  // tell servo 3 to go to position in variable 'pos'
    RIGHT.write(pos);   // tell servo 4 to go to position in variable 'pos'
    PINKY.write(pos);   // tell servo 5 to go to position in variable 'pos' 
    delay(20);          // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 1) 
  { // goes from 180 degrees to 0 degrees
    THUMB.write(pos);   // tell servo 1 to go to position in variable 'pos'
    INDEX.write(pos);   // tell servo 2 to go to position in variable 'pos'
    MIDDLE.write(pos);  // tell servo 3 to go to position in variable 'pos'
    RIGHT.write(pos);   // tell servo 4 to go to position in variable 'pos'
    PINKY.write(pos);   // tell servo 5 to go to position in variable 'pos' 
    delay(20);          // waits 15 ms for the servo to reach the position
  }

*/
}
