// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Capacitor pins
#define analogPin 0
#define chargePin 13
#define dischargePin 10
#define resistorValue 10000.0F

unsigned long startTime;
unsigned long elapsedTime;
float microFarads;
float nanoFarads;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // // Print a message to the LCD.
  // lcd.print("hello, world!");

  /////////////////////////////////////////////////////////
  /// Capacitor code
  Serial.begin(9600);
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // lcd.setCursor(0, 1);
  // // print the number of seconds since reset:
  // lcd.print(millis() / 1000);

  ///////////////////////////////////////////////
  // Capacitor code
  digitalWrite(chargePin, HIGH);
  startTime = millis();
  while (analogRead(analogPin) < 648) {
  }

  elapsedTime = millis() - startTime;
  microFarads = ((float)elapsedTime / resistorValue) * 1000;
  Serial.print(elapsedTime);
  Serial.print(" mS    ");
  // lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(elapsedTime);
  lcd.setCursor(7, 0);
  lcd.print(" ms");

  lcd.setCursor(0, 1);

  if (microFarads > 1) {
    Serial.print((long)microFarads);
    Serial.println(" microFarads");
    // lcd
    
    lcd.print((long)microFarads);
    lcd.print(" microFarads");
  }

  else {
    nanoFarads = microFarads * 1000.0;
    Serial.print((long)nanoFarads);
    Serial.println(" nanoFarads");
    // lcd
    lcd.print((long)nanoFarads);
    lcd.print(" nanoFarads");
    // delay(500);
  }

  digitalWrite(chargePin, LOW);
  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);
  while (analogRead(analogPin) > 0) {
  }

  pinMode(dischargePin, INPUT);
  delay(500);
}