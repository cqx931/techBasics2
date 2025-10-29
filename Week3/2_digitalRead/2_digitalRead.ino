/*
Digital Read with Tilt Switch
*/
int value = 0;
const int pin = 3;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(pin,INPUT_PULLUP);
}


void loop() {
  Serial.println(digitalRead(pin));
} 
