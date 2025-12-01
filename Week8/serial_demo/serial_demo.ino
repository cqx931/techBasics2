/***
This sketch simply sends data to serial every second
Use this with Python Demo Mode 1 (Continuous Reading)
***/

int counter = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  Serial.print("Count: ");
  Serial.println(counter);
  counter++;
  delay(1000);  // Send every 1 second
}
