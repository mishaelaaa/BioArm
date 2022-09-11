#include <Servo.h>

//Threshold for servo motor control with muscle sensor. 
//You can set a threshold according to the maximum and minimum values of the muscle sensor.
#define THRESHOLD 500

//Pin number where the sensor is connected. (Analog 0)
#define EMG_PIN 0

#define SAMPLE_RATE 2500

//BAUDRATE set to 115200
#define BAUD_RATE 115200

// create servo object to control a servo
Servo THUMB;
Servo INDEX;
Servo MIDDLE;
Servo RIGHT;
Servo PINKY;
Servo WRIST_RIGHT;
Servo WRIST_FRONT;

/*-------------------------------- void setup ------------------------------------------------*/

void setup() 
{
  //BAUDRATE set to 115200, remember it to set monitor serial properly. 
  //Used this Baud Rate and "NL&CR" option to visualize the values correctly.
  Serial.begin(BAUD_RATE);

  //Set servo motor to digital pin N
  THUMB.attach(3,600,2300);   // (pin, min, max)
  INDEX.attach(5,600,2300);   // (pin, min, max)
  MIDDLE.attach(6,600,2300);  // (pin, min, max)
  RIGHT.attach(9,600,2300);   // (pin, min, max)
  PINKY.attach(10,600,2300);  // (pin, min, max)
}

/*--------------------------------  void loop  ------------------------------------------------*/

void loop() 
{  
  // Calculate elapsed time
  static unsigned long past = 0;
  unsigned long present = micros();
  unsigned long interval = present - past;
  past = present;

  // Run timer
  static long timer = 0;
  timer -= interval;

  // Sample
  if(timer < 0)
  {
    timer += 1000000 / SAMPLE_RATE;
    float sensor_value = analogRead(EMG_PIN);
    float signal = EMGFilter(sensor_value);

    THUMB.write(0);  // tell servo to go to a particular angle
    INDEX.write(0);  
    MIDDLE.write(0);  
    RIGHT.write(0);  
    PINKY.write(0);         
    delay(500); 
    
    //If the sensor value is GREATER than the THRESHOLD, the servo motor will turn to 170 degrees.
    if(signal < THRESHOLD)
    {
      THUMB.write(170);  
      INDEX.write(170);  
      MIDDLE.write(170);  
      RIGHT.write(170);  
      PINKY.write(170);       
      delay(1000); 
    }
    
    //If the sensor is LESS than the THRESHOLD, the servo motor will turn to 10 degrees.
    else
    {
      THUMB.write(10);  
      INDEX.write(10);  
      MIDDLE.write(10);  
      RIGHT.write(10);  
      PINKY.write(10);    
      delay(100); 
    }
    
    Serial.println(signal);
    delay(1000); 
  }
}

float EMGFilter(float input)
{
  float output = input;
  {
    static float z1, z2; // filter section state
    float x = output - 0.05159732*z1 - 0.36347401*z2;
    output = 0.01856301*x + 0.03712602*z1 + 0.01856301*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -0.53945795*z1 - 0.39764934*z2;
    output = 1.00000000*x + -2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - 0.47319594*z1 - 0.70744137*z2;
    output = 1.00000000*x + 2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2; // filter section state
    float x = output - -1.00211112*z1 - 0.74520226*z2;
    output = 1.00000000*x + -2.00000000*z1 + 1.00000000*z2;
    z2 = z1;
    z1 = x;
  }
  return output;
}
