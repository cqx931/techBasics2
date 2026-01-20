
/***
Example code for four-digit seven segment display
Miuzei 3461BS Common Anode
Elegoo is 5641AS Common Cathod
***/

#include "SevSeg.h"
SevSeg sevseg; 

int PATTERN_CHANGE_TIME = 2000;
int TOTAL_NUMBER = 3;
int n = 0;
long timer = millis() - PATTERN_CHANGE_TIME;

void setup(){
  byte numDigits = 4;
  // Digit 1-4, change the order to 13,12,11,10 if you have 5641AS
  byte digitPins[] = {10, 11, 12, 13}; 
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Seg A-G, DP 
  // Change this to COMMON_CATHODE if you have 5641AS
  byte hardwareConfig = COMMON_ANODE; 

  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop(){
  // Cycle to the next case every two second
  if (millis() > (timer + PATTERN_CHANGE_TIME)) {
    if (n==0) {
      sevseg.setNumber(1234);
    } else if (n ==1){
      sevseg.setNumber(3141,3); //second parameter, decimal position
    } else if (n==2){
      sevseg.setChars("abcd");
    }
    n++;
    if (n >= TOTAL_NUMBER) n = 0;
    timer = millis();
  }
  sevseg.refreshDisplay(); // Must run repeatedly
}
