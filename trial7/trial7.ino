// drive a hobby servo motor

#include <Servo.h>

// make a servo "object"
Servo doorMotor;

const int DOORMOTORPIN = 3;

void setup(){
  //tell the arduino where the motor is plugged in 
  doorMotor.attach(DOORMOTORPIN);
}

void loop(){
  // make the motor go to 17deg
  doorMotor.write(1);
  delay(1000);
  doorMotor.write(175); // make the motor go to 124deg
  delay(1000);
}