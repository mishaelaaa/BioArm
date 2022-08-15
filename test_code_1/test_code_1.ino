//EMG sensor robotic hand controller 
//This code is for controlling a robotic hand with
//an EMG sensor. 
//
//© Au Robots 8.4.2017


//Necessary for controlling the servos
#include <Servo.h> 
#define emg A0
double value_emg;

const int x = 60

///// This is the reference value and it
//will depend on your setup. You have to find it out 
//yourself by looking at the serial monitor and finding
//a value between the maximum and minimum value.

//Naming the servos
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() 
{ 
  //Starting the serial monitor
  Serial.begin(9600); 
  
  //Configuring servo pins
  servo2.attach(10); // pinky
  servo3.attach(11); //ring
  servo4.attach(3); // middle
  servo5.attach(6); //index
  servo6.attach(5); //thumb
} 


void loop() 
{ 
  //Printing the EMG data
    value_emg = analogRead(emg); 
    Serial.println(value_emg);
  
  //If the EMG data is greater than x the hand closes
    if(value_emg > x) 
    {
      servo2.write(180);
      servo3.write(148);
      servo4.write(89);
      servo5.write(180);
      servo6.write(180);
    }
  
  //If the EMG data is lower than x the hand opens
    else if (value_emg < x) 
    {
      servo2.write(38);
      servo3.write(10);
      servo4.write(0);
      servo5.write(16);
      servo6.write(16);
    }
  
  //A delay to slow down the process
    delay(100);
} 
