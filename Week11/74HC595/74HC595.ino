//**************************************************************//
// Simple 74HC595 demo
//****************************************************************
//Pin connected to STCP(Storage  Registers Clock Input) of 74HC595 - pin 12
int latchPin = 4;
//Pin connected to SHCP(Shift Register Clock Input) of 74HC595 - pin 11
int clockPin = 8;
//Pin connected to DS of 74HC595 - pin 14
int dataPin = 9;
// A byte stores an 8-bit number, from 0 to 255
// 0b tells arduino that we are using binary notation instead of decimal
byte LED = 0b10101010;  // modify this to the pattern you want to display
// 1 -> 00000001
// 2 -> 00000010
// 4    00000100
// 8    00001000     

// 128 -> 1000 0000
// 1 -> 0000 0001
void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin,LOW);
  // shiftOut(dataPin, clockPin, bitOrder, value)
  shiftOut(dataPin,clockPin,LSBFIRST,LED);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(latchPin,LOW);
  // shiftOut(dataPin, clockPin, bitOrder, value)
  shiftOut(dataPin,clockPin,MSBFIRST,LED);
  digitalWrite(latchPin,HIGH);



  // this shifts the bits towards the left
  // LED = LED / 128 + LED * 2; 

  // this shifts the bits towards the right
  // LED = LED / 2 + LED * 128;

  // flipping
  // LED = 255 - LED;

  // 2 bits, 0-3, 4
  // 00 -> 11 , 0 -> 3
  // 01 -> 10,  1 -> 2
  // value = 3 - value

  delay(500);
 
}