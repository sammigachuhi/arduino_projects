#include <LiquidCrystal.h>

// Initialize the library with your direct parallel LCD wiring pins
// Syntax: LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);

// Time tracking variables (starts at 12:00:00)
int hours = 12;
int minutes = 0;
int seconds = 0;

unsigned long lastSecondTime = 0;

void setup() {
  lcd.begin(16, 2); // Initialize 16x2 LCD
  
  lcd.setCursor(0, 0);
  lcd.print("ESP32 Clock");
}

void loop() {
  // Check if 1 second (1000 milliseconds) has elapsed
  if (millis() - lastSecondTime >= 1000) {
    lastSecondTime = millis();
    
    seconds++;
    
    // Handle time rollovers
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) {
          hours = 0; // Switch to 1-12 format (change to 24 if preferred)
        }
      }
    }
    
    // Print the formatted time on the second row
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    
    // Add leading zeros for neat formatting
    if (hours < 10) lcd.print("0");
    lcd.print(hours);
    lcd.print(":");
    
    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print(":");
    
    if (seconds < 10) lcd.print("0");
    lcd.print(seconds);
    lcd.print("   "); // Trailing spaces to clear out old digit remnants
  }
}
