#include <Servo.h> 

// create servo object to control a servo
Servo THUMB;
Servo INDEX;
Servo MIDDLE;
Servo RIGHT;
Servo PINKY;
Servo WRIST_RIGHT;
Servo WRIST_FRONT;

int pos = 0;    // variable to store the servo position

void setup() 
{
  Serial.begin(9600);
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
  
  // serial print message
  Serial.println("Test_for_5_servos.V0.1"); 
}

void loop() 
{
  for (pos = 0; pos <= 180; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    THUMB.write(pos);   // tell servo 1 to go to position in variable 'pos'
    INDEX.write(pos);   // tell servo 2 to go to position in variable 'pos'
    MIDDLE.write(pos);  // tell servo 3 to go to position in variable 'pos'
    RIGHT.write(pos);   // tell servo 4 to go to position in variable 'pos'
    PINKY.write(pos);   // tell servo 5 to go to position in variable 'pos' 
    delay(10);          // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 1) 
  { // goes from 180 degrees to 0 degrees
    THUMB.write(pos);   // tell servo 1 to go to position in variable 'pos'
    INDEX.write(pos);   // tell servo 2 to go to position in variable 'pos'
    MIDDLE.write(pos);  // tell servo 3 to go to position in variable 'pos'
    RIGHT.write(pos);   // tell servo 4 to go to position in variable 'pos'
    PINKY.write(pos);   // tell servo 5 to go to position in variable 'pos' 
    delay(10);          // waits 15 ms for the servo to reach the position
  }
}
