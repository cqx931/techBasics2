/****
Two Servos Controlled by a Joystick
***/

#include <Servo.h>   // Include the Servo library

Servo myservo1;  // Create the first servo object
Servo myservo2;  // Create the second servo object

const int x_pin = A0;
const int y_pin = A1;
const int sw_pin = 2;

int x_value = 0;
int y_value = 0;

void setup() {
  myservo1.attach(9);  // Attach pin 9 to the servo object 1
  myservo2.attach(10);  // Attach pin 10 to the servo object 2
  // Init pins for Joystick
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  
}

void loop() {
  // Read all values
  x_value = analogRead(x_pin);
  y_value = analogRead(y_pin);

  // Map values for servos
  x_value = map(x_value, 0,1023,0,180);
  y_value = map(y_value, 0,1023,0,180);
  
  myservo1.write(x_value);
  myservo2.write(y_value);

  // Some delay
  delay(200);
   
}