//**************************************************************//
// Challenges for 74HC595
//****************************************************************
//Pin connected to STCP(Storage  Registers Clock Input) of 74HC595 - pin 12
int latchPin = 4;
//Pin connected to SHCP(Shift Register Clock Input) of 74HC595 - pin 11
int clockPin = 8;
//Pin connected to DS of 74HC595 - pin 14
int dataPin = 9;
// A byte stores an 8-bit number, from 0 to 255
// 0b tells arduino that we are using binary notation instead of decimal
byte LED = 0b00000111;  // modify this to the pattern you want to display

int mode = 1; 
// mode 1 for circular shifting to the left, 
// mode 2 for circular shifting to the right
// mode 3 for flipping the bit

void setup() {
  Serial.begin(9600); 
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {

  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,LED);
  digitalWrite(latchPin,HIGH);
  
  if (mode == 1) { // circular shifting to the left
    LED = LED / 128 + LED * 2;
  } else if (mode == 2) { // circular shifting to the right
    LED = LED / 2 + LED * 128;
  } else if (mode == 3) {
    LED = 255 - LED;
  }

  delay(500);
}