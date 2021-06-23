// Include Libs
#include <LiquidCrystal_I2C.h> // LCD   16x2        Lib
#include <DS3231.h>            // Real  Time Clock Lib
#include <Wire.h>              // i2c    Protocol    Lib

// Modules Setup
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
// Define Real Time Clock module
DS3231 rtc(SDA , SCL);

// Setup Void
void setup() {
  // Begin Modules
  rtc.begin();  // RTC
  lcd.init();  // LCD

  // Turn the backlight on
  lcd.backlight();

  // RTC Setup
  rtc.setDOW(FRIDAY);         // Set the day  to like  : SUNDAY
  rtc.setTime(15, 50, 0);     // Set the time to like : 12:00:00 (24hr format)
  rtc.setDate(11, 9, 2020);   // Set the date to like : January 1st, 2014
}

// Main Loop
void loop() {
  // Define values
  String tim = rtc.getTimeStr(); // Time
  String dat = rtc.getDateStr(); // Date

  // Print Time
  lcd.setCursor(0, 0); // Set spot
  lcd.print("Time: ");
  lcd.print(tim);      // Print Time

  // Print Date
  lcd.setCursor(0, 1); // Set spot
  lcd.print("Date: ");
  lcd.print(dat);      // Print Date
}
