/***
Example Code to make a stepper motor move without stopping the sketch
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11);

// This number defines how many steps are needed per one revolution
// this is the case for miuzei, 4076/4096 for elegoo
// http://forum.arduino.cc/index.php?topic=71964.15
const int stepsPerRevolution = 1024;
bool moveClockwise = true;
int stepsLeft = 0; // how many steps are left from the current movement


void setup()
{
  // Start serial
  Serial.begin(9600);
 
  // Stepper Setups
  stepper.setRpm(6);  // The default is ~16.25rpm
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources
  stepper.setTotalSteps(stepsPerRevolution); 
  // move one round
  stepper.newMove(moveClockwise, stepsPerRevolution);
}

void loop() {
  // this is necessary to keep in the loop with newMove()
  stepper.run();
  // we can now do other things, like digitalRead()/analogRead() in the loop because newMove doesn't stop the process

  stepsLeft = stepper.getStepsLeft();
  // if the current move is done...
  if (stepsLeft == 0){
    Serial.println("0");
    // let's start a new move in the reverse direction
    moveClockwise = !moveClockwise; // reverse direction
    stepper.newMove(moveClockwise, stepsPerRevolution/3); // move 120 degrees from current position
  } 

}