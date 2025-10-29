/*
Analog Read
*/
int readingValue = 0;
int brightness = 0;
const int ledPin = 5;

void setup() {
  // open the serial port at 9600 bps:
  Serial.begin(9600); 
  pinMode(A0,INPUT);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  // get reading from A0
  readingValue = analogRead(A0);
  Serial.println(readingValue);
  // map it to 0, 255 for analogWrite
  brightness = map(readingValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
} 
