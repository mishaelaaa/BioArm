#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define THUMB
#define INDEX
#define MIDDLE
#define RIGHT
#define PINKY
#define WRIST_RIGHT
#define WRIST_FRONT

/*
#define SERVOMIN  50    // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  4000  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50   // Analog servos run at ~50 Hz updates
*/

#define SERVOMIN  50    // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  4000  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50   // Analog servos run at ~50 Hz updates

// our servo # counter
uint16_t servonum = 0;
uint16_t state_g = 0;
uint16_t array_servos[THUMB INDEX MIDDLE RIGHT PINKY WRIST_RIGHT WRIST_FRONT] = { 0, 1, 2, 3, 4, 5, 6 };

void setup() 
{
  Serial.begin(9600);
  Serial.println("4 channel Servo test!");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
}

void loop() 
{
  state_g=0;
  if(state_g==0)
  {
    Serial.print("State "); Serial.println(state_g);
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
    {
      for(servonum=0; servonum<4; servonum++)
        {
          pwm.setPWM(servonum, 0, pulselen);
        }
    }
    state_g=1;
  }

  if(state_g==1)
  {
    Serial.print("State "); Serial.println(state_g);
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--)
    {  
      for(servonum=0; servonum<4; servonum++)
        pwm.setPWM(servonum, 0, pulselen);
    }
    state_g=2;
  }

  if(state_g==2)
  {
    Serial.print("State "); Serial.println(state_g);
    for (uint16_t microsec = USMIN; microsec < USMAX; microsec++)
    {
      for(servonum=0; servonum<4; servonum++)
        pwm.writeMicroseconds(servonum, microsec);
    } 
    state_g=3;   
  }
  
  if(state_g==3)
  {
    Serial.print("State "); Serial.println(state_g);
    for (uint16_t microsec = USMAX; microsec > USMIN; microsec--)
    {
      for(servonum=0; servonum<4; servonum++)
        pwm.writeMicroseconds(servonum, microsec);
    }
    state_g=4;  
  }

  if(state_g==4)
  {    
    Serial.print("State "); Serial.println(state_g);
    for (uint16_t microsec = USMAX-USMIN; microsec > USMIN; microsec--)
    {
      for(servonum=0; servonum<4; servonum++)
        pwm.writeMicroseconds(servonum, microsec);
    }
    for (uint16_t microsec = USMAX-USMIN; microsec > USMIN; microsec++)
    {
      for(servonum=0; servonum<4; servonum++)
        pwm.writeMicroseconds(servonum, microsec);
    }
  }
  //state_g=0;  
  //delayMicroseconds(50);      // pauses for 50 microseconds
}
