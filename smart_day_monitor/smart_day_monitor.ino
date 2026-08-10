///////////////////////////////
// LCD Code
#include <LiquidCrystal.h> 

///////////////////////////////////
// Include LED Code
#include "SevSeg.h"
SevSeg sevseg;

////////////////////////////
// Temperature sensor 
#include <DHT.h>
#define DHTPIN 6
#define DHTTYPE DHT11 // sensor type

DHT dht(DHTPIN, DHTTYPE);

////////////////////////////////
/// LCD pins 
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

////////////////////////////////
// 


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ////////////////////////////////////////
  // Set up LCD 
  lcd.begin(16, 2);
  // Print message to LCD 
  // lcd.print("Hello, Gachuhi!");

  
  //////////////////////////////////////
  // Initialize DHT sensor 
  dht.begin();

  pinMode(A0, INPUT);


}

void loop() {

  /////////////////////////
  // Set cursor for LCD, column 0, line 1 
  lcd.setCursor(0, 1);

  ////////////////////////////
  // Read temperature Celsius 
  float t = dht.readTemperature();

  lcd.print(t);

  

  // if (isnan(t)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   return;
  // }

  //////////////////////////////////////
  /// LD 
  

  // if (temperature < 10) {
  //   lcd.setCursor(2, 0);
  //   lcd.print("COLD...");
    // delay(500);
    // lcd.clear();
    // delay(500);
  // } else if ( (temperature >= 10) && (t < 22) ) {
  //   lcd.setCursor(2, 0);
  //   lcd.print("WARM...");
    // delay(500);
    // lcd.clear();
    // delay(500);
  // } else {
  //   lcd.setCursor(2, 0);
  //   lcd.print("HOT...");
  //   delay(500);
    // lcd.clear();
    // delay(500);
  // }

  // ////////////////////////////
  // // LED 
  // sevseg.setNumber(t, 2);
  // sevseg.refreshDisplay();

  
  // Serial.println(t);
  // delay(1000);

}

