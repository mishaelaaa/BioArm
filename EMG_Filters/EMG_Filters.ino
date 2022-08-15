#include <Servo.h>

#define SAMPLE_RATE 2500
#define BAUD_RATE 115200
#define INPUT_PIN A0
#define TARGET 60

int Value_EMG_PIN = 0;      // variable to store readed value of INPUT_PIN
int Map_Value_EMG_PIN = 0;  // variable to store value after mapping of emg value
int Position_Servo = 0;     // variable to store the servo position

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
  // Serial connection begin
  Serial.begin(BAUD_RATE);
  
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
}

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
    float sensor_value = analogRead(INPUT_PIN);
    float signal = EMGFilter(sensor_value);
    
    Map_Value_EMG_PIN = map(signal, 0, 1023, 0, 180);
    
    Serial.print("signal : ");   Serial.println(signal);
    Serial.print("Map Value : ");Serial.println(Map_Value_EMG_PIN);

    //If the EMG data is greater than x the hand closes
    if(Map_Value_EMG_PIN > TARGET) 
    {
      for (Position_Servo = 0; Position_Servo <= 180; Position_Servo += 1) 
      { 
        // goes from 0 degrees to 180 degrees  
        // in steps of 1 degree
        THUMB.write(Position_Servo);   // tell servo 1 to go to position in variable 'pos'
        INDEX.write(Position_Servo);   // tell servo 2 to go to position in variable 'pos'
        MIDDLE.write(Position_Servo);  // tell servo 3 to go to position in variable 'pos'
        RIGHT.write(Position_Servo);   // tell servo 4 to go to position in variable 'pos'
        PINKY.write(Position_Servo);   // tell servo 5 to go to position in variable 'pos' 
        //delay(15);                     // waits 15 ms for the servo to reach the position
      }
    }
    
    if(Map_Value_EMG_PIN < TARGET) 
    {
      for (Position_Servo = 180; Position_Servo >= 0; Position_Servo -= 1) 
      { 
        // goes from 180 degrees to 0 degrees
        THUMB.write(Position_Servo);   // tell servo 1 to go to position in variable 'pos'
        INDEX.write(Position_Servo);   // tell servo 2 to go to position in variable 'pos'
        MIDDLE.write(Position_Servo);  // tell servo 3 to go to position in variable 'pos'
        RIGHT.write(Position_Servo);   // tell servo 4 to go to position in variable 'pos'
        PINKY.write(Position_Servo);   // tell servo 5 to go to position in variable 'pos' 
        //delay(15);                     // waits 15 ms for the servo to reach the position
      }
    }
  }
  //A delay to slow down the process
  //delay(10);
}

// Band-Pass Butterworth IIR digital filter, generated using filter_gen.py.
// Sampling rate: 500.0 Hz, frequency: [74.5, 149.5] Hz.
// Filter is order 4, implemented as second-order sections (biquads).
// Reference: 
// https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.butter.html
// https://courses.ideate.cmu.edu/16-223/f2020/Arduino/FilterDemos/filter_gen.py

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
