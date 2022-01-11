 //Write a program to interface a stepper motor with Esp32 and move the motor 5 steps forward and 10 steps backward. 
//Am using ULN300DRIVER
         //ESP32    //ULN300
         //18          IN1
         //19          IN2
         //12          IN3
         //13          IN4 
         //VIN         VCC
         //GND         GND
#include <Stepper.h>

int Steps=2048; //for torque, I am using 32 steps for motor revolution, then 64 to 1 full rev, so combination of 32by64 will be 2048 matchable.
Stepper mystepper(Steps, 18, 12, 19, 13);//pin 1 , 3, 2, 4

void setup() {
  mystepper.setSpeed(10);
  Serial.begin(9600);
}
void loop() {
  mystepper.step(5);
  delay(500);
  mystepper.step(-10);
}
