/// Libraries
#include <LiquidCrystal.h>

// LCD initialization
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Piezometer 
int piezometerPin = 8;

// LED bulbs
int redLED = 7;
int yellowLED = 13;
int greenLED = A0;

// Water Sensor pin
int waterSensorPin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // LCD 
  lcd.begin(16, 2);
  lcd.print("Hello Gachuhi!");

  // LED bulbs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

}

void loop() {
  // // put your main code here, to run repeatedly:
  
  // Read water values 
  int waterSensorValue = analogRead(waterSensorPin);
  // Serial.println(waterSensorValue);
  if (waterSensorValue < 200) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    analogWrite(greenLED, 0);
    lcd.setCursor(0, 0);
    lcd.print("--EMPTY TANK--");
    lcd.setCursor(0, 2);
    lcd.print(waterSensorValue);
    lcd.print("Litres");
    delay(500);
    lcd.clear();
  } else if (waterSensorValue >= 200 && waterSensorValue < 400) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    analogWrite(greenLED, 0);
    lcd.setCursor(0, 0);
    lcd.print("--HALF TANK--");
    lcd.setCursor(0, 2);
    lcd.print(waterSensorValue);
    lcd.print("Litres");
    delay(500);
    lcd.clear();
  } else if (waterSensorValue >= 400 && waterSensorValue < 620) {
    // Piezometer Pin Tone 
    tone(piezometerPin, 1000, 500);
    analogWrite(greenLED, 255);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    lcd.setCursor(0, 0);
    lcd.print("--FULL TANK--");
    lcd.setCursor(0, 2);
    lcd.print(waterSensorValue);
    lcd.print("Litres");
    delay(500);
    lcd.clear();
  }
  // delay(200);
}


