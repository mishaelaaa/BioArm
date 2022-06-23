#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  50   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  4000   // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50   // Analog servos run at ~50 Hz updates

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
  int servonum=0; 
  while(true)
  {
    if (servonum > 3) 
      servonum = 0; // Testing the first 4 servo channels
    
    // Drive each servo one at a time using setPWM()
      Serial.println(servonum);
      for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
      {
        if(servonum>3)
        {
          pwm.setPWM(servonum, 0, pulselen);
          delay(100);
          servonum++;
        }
      }
      delay(100);
  
      for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--)
      {
        if(servonum>3)
        {
          pwm.setPWM(servonum, 0, pulselen);
          delay(100);
          servonum++;
        }
      }
      delay(100);
  
      // Drive each servo one at a time using writeMicroseconds(), it's not precise due to calculation rounding!
      // The writeMicroseconds() function is used to mimic the Arduino Servo library writeMicroseconds() behavior. 
      for (uint16_t microsec = USMIN; microsec < USMAX; microsec++)
      {
        if(servonum>3)
        {
          pwm.writeMicroseconds(servonum, microsec);
          delay(100);
          servonum++;
        }
      }
      delay(100);
  
      for (uint16_t microsec = USMAX; microsec > USMIN; microsec--)
      {
        if(servonum>3)
        {
          pwm.writeMicroseconds(servonum, microsec);
          delay(100);
          servonum++;
        }
      }
      delay(100);
  
      servonum++; 
  }
    
}
