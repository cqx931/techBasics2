/***
This sketch waits for a "BLINK" command from Python
When received, it blinks the LED on pin 13 twice
Use this with Python Demo Mode 2 (Send & Receive)
***/

const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  delay(1000);
}

void loop() {
  // Check if data is available from serial

  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "BLINK") {
      // Blink LED twice
      for (int i = 0; i < 2; i++) {
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
        delay(300);
      }
    }
  }
}
