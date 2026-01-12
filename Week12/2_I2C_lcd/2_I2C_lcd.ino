/***
LCD with I2C and Customize Characters
***/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F depending on your setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte Heart[8] = {
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};


void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.createChar(0, Heart);
  // The rest works the same
  lcd.clear();
  lcd.print("Hello World!");
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.print("Tech Basics II");
  
}

void loop() {
  // You can update the display here if needed
}
