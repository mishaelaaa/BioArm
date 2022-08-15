#include <Servo.h>

//Threshold for servo motor control with muscle sensor. 
//You can set a threshold according to the maximum and minimum values of the muscle sensor.
#define THRESHOLD 250

//Pin number where the sensor is connected
#define EMG_PIN 0

//Pin number where the servo motor is connected
#define SERVO_PIN 9

//Define Servo motor
Servo SERVO_1;
int Value_EMG_PIN = 0;
int Map_Value_EMG_PIN = 0;

/*-------------------------------- void setup ------------------------------------------------*/

void setup()
{
  //BAUDRATE set to 115200 to set monitor serial properly
  //Used this Baud Rate and "NL&CR" option to visualize the values correctly
  Serial.begin(115200);
  
  //Set servo motor to digital pin 
  SERVO_1.attach(SERVO_PIN);
}

/*--------------------------------  void loop  ------------------------------------------------*/

void loop()
{

  //The "Value" variable reads the value from the analog pin to which the sensor is connected.
  Value_EMG_PIN = analogRead(EMG_PIN);

  //If the sensor value is GREATER than the THRESHOLD, the servo motor will turn to 170 degrees.
  if(Value_EMG_PIN > THRESHOLD)
  {
    Map_Value_EMG_PIN = map(Value_EMG_PIN, 0, 1023, 0, 180);
    SERVO_1.write(180);
  }
  
  //If the sensor is LESS than the THRESHOLD, the servo motor will turn to 10 degrees.
  else
    SERVO_1.write(10);

  //You can use serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand.
  Serial.println(value);
}
