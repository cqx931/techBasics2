//**************************************************************//
// 74HC595 Binary Counter
//****************************************************************
//Pin connected to STCP(Storage  Registers Clock Input) of 74HC595 - pin 12
int latchPin = 4;
//Pin connected to SHCP(Shift Register Clock Input) of 74HC595 - pin 11
int clockPin = 8;
//Pin connected to DS of 74HC595 - pin 14
int dataPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
  // count from 0 to 255 and display the number on the LEDs
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    Serial.println(numberToDisplay, BIN); // Serial print in binary
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(1000);
  }
}