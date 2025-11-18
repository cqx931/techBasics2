/***
Example Code to make a stepper motor move to specific location
Notice that the Arduino sketch "pauses" during move()
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11);

// This number defines how many steps are needed per one revolution
// this is the case for miuzei, 4076/4096 for elegoo
// http://forum.arduino.cc/index.php?topic=71964.15
const int stepsPerRevolution = 1024;

void setup()
{
  Serial.begin(9600);
  stepper.setRpm(10);  // the default is ~16.25rpm
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources
  stepper.setTotalSteps(stepsPerRevolution); 
}

void moveDemo() {
  // ask the stepper motor to move relative steps/degree
  // or use move (boolean clockwise, int numSteps);
  //        moveDegrees (boolean clockwise, int degrees);

  stepper.moveCW(stepsPerRevolution*2); // 2 rounds
  delay(2000); 
  stepper.moveCCW(stepsPerRevolution/4); // 90 degree
  delay(2000); 
  stepper.moveDegreesCW (720); // you can set the angle
  delay(2000); 
  stepper.moveDegreesCCW (90); 
  delay(2000);  

}

void moveToDemo() {
  // To move to an absolute position, it has to be less than 360 degree
  Serial.print("current step position: "); 
  int nStep = stepper.getStep();
  Serial.println(nStep);

  stepper.moveTo(true, stepsPerRevolution/4);  // 90 degree
  delay(1000);
  stepper.moveTo(true, stepsPerRevolution/2); // move to 180 degree position 
  delay(2000);

  Serial.print("current step position: "); 
  nStep = stepper.getStep();
  Serial.println(nStep);

  stepper.moveTo(false, 0);
  delay(2000);   

  // moveToDegree() doesn't seem to work as expected, 
  // so I do not recommend to use that function
}

void loop() {
  // There are two demos in this sketch, one is for move
  //moveDemo(); 
  //moveToDemo();
  Serial.println("before move");
  stepper.moveCW(stepsPerRevolution*2);
  Serial.println("after move");

  delay(2000);


}