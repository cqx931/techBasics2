/***
This is a simple demo that reads the state of a touch sensor on bautrate 115200
0 for not touched, 1 for touched
***/
const int touchPin = 2;
const int analogPin = A0;
void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT); 
  delay(1000);
}

void loop() {
  int state = digitalRead(touchPin);
  Serial.print("Touch: ");
  Serial.println(state);
  int value = analogRead(analogPin);
  Serial.print("Pot: ");
  Serial.println(value);
  delay(100);  // Read every 100ms
}
