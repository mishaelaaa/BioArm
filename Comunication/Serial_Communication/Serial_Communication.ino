#include <Servo.h>

#define BAUD_RATE 115200
#define INPUT_PIN A0

int Value_EMG_PIN = 0;      // variable to store readed value of INPUT_PIN
int Map_Value_EMG_PIN = 0;  // variable to store value after mapping of emg value

void setup() 
{
  // Serial connection begin
  Serial.begin(BAUD_RATE);
  
  pinMode(INPUT_PIN, INPUT);
}

void loop() 
{
  float sensor_value = analogRead(INPUT_PIN);
  
  Map_Value_EMG_PIN = map(sensor_value, 0, 1023, 0, 180);
  
  //Serial.print("Signal Value: ");   
  Serial.println(sensor_value);
  //Serial.print("Map Value : ");     
  //Serial.println(Map_Value_EMG_PIN);

}
