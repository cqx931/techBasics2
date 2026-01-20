/***
Example code for using the one-digit seven segent display 
5161AS (Comon Cathode)
***/

#include "SevSeg.h"
SevSeg sevseg; 

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // pin A-G & DP
    byte hardwareConfig = COMMON_CATHODE; 

    bool resistorsOnSegments = false;

    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);

    Serial.begin(9600);
}

void loop(){
  for(int i=0; i<=9; i++) {
    Serial.print(i);
    sevseg.setNumber(i);
    sevseg.refreshDisplay(); 
    delay(1000); 
  }      
}
