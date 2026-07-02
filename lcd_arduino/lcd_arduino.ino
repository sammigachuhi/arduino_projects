#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);

  // lcd.begin(16, 2);
  // lcd.print("Hello, world!");
  lcd.begin(16, 2);
  // lcd.print("Hello, world!");
  // lcd.setCursor(2, 1);
  lcd.print("Hello, World!");


}

void loop() {
  // lcd.print("hello, world");
  // delay(500);
  // lcd.clear();
  // delay(500);
  // lcd.home();
  // lcd.print("XXX");

  lcd.scrollDisplayLeft();
  delay(200);

}


