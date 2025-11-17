/***
Example Code to make a stepper motor step
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11); 

// This number defines how many steps are needed per one revolution
// this is the case for miuzei, 4076/4096 for elegoo
// http://forum.arduino.cc/index.php?topic=71964.15
const int stepsPerRevolution = 1024;

boolean moveClockwise = true;

void setup() {
  
  stepper.setRpm(10);  // the default is ~16.25rpm
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources

  stepper.setTotalSteps(1024); 

  Serial.begin(9600);
}

void loop() {
  
  for (int i = 0; i < stepsPerRevolution; i++){
      // let's move one step
    stepper.step(moveClockwise);

    int nStep = stepper.getStep(); // returns current miniStep position

    // Log if it's divisible by 64...
    if (nStep%64==0){ 
      // let's print the position to the console
      Serial.print("current step position: "); 
      Serial.print(nStep);
      Serial.println();
    }
  }

  delay(1000);
}

