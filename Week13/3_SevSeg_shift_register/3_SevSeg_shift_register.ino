/***
 Example of a seven-segment display with:
  - segment pins controlled via 1 shift register(74HC595) and 
  - digit pins connected to the Arduino directly
***/

#include "SevSegShift.h"

// pins for shift register
#define SHIFT_PIN_SHCP 6
#define SHIFT_PIN_STCP 7
#define SHIFT_PIN_DS   8

SevSegShift sevsegshift(SHIFT_PIN_DS, SHIFT_PIN_SHCP, SHIFT_PIN_STCP, 
1, /* number of shift registers there is only 1 Shiftregister 
      used for all Segments (digits are on Controller)
      default value = 2
      */
true /* Digits are connected to Arduino directly 
        default value = false
      */
);

int deciSeconds = 0;

void setup() {
  byte numDigits = 4;
  // Digit 1-4, change the order to 13,12,11,10 if you have 5641AS
  byte digitPins[] = {10,11,12,13};
  byte segmentPins[] = {1,2,3,4,5,6,7,0}; // these are the PINs of the ** Shift register **
  // Change this to COMMON_CATHODE if you have 5641AS
  byte hardwareConfig = COMMON_ANODE;

  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevsegshift.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevsegshift.setBrightness(90);
}

void loop() {
  long timer = millis();
  
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    
    // Reset to 0 after counting for 1000 seconds.
    if (deciSeconds == 10000) { 
      deciSeconds=0;
    }
    sevsegshift.setNumber(deciSeconds, 1);
  }

  sevsegshift.refreshDisplay(); // Must run repeatedly
}
