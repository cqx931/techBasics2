/**
Simple Example to test DC Motor
**/
const int motorPin = 3;

void setup(){
  pinMode(motorPin,OUTPUT);
}

void loop(){
  digitalWrite(motorPin, HIGH);
  delay(4000);
  digitalWrite(motorPin, LOW);
  delay(4000);
}