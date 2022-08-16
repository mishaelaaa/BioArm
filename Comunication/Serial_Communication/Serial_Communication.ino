#include <Servo.h>

#define BAUD_RATE 115200
#define INPUT_PIN 0

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
  Value_EMG_PIN = analogRead(INPUT_PIN);  
  Map_Value_EMG_PIN = map(Value_EMG_PIN, 0, 1023, 0, 100);
  
  //Serial.print("Signal Value: "); 
  //Serial.println(Value_EMG_PIN);
  
  //Serial.print("Signal Value: ");   
  //Serial.println(sensor_value);
  
  //Serial.print("Map Value : ");     
  Serial.println(Map_Value_EMG_PIN);
}
