#include "SevSeg.h"
SevSeg sevseg; // Create sevseg object

////////////////////////////
// Thermistor
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03; 
float c2 = 2.378405444e-04;
float c3 = 2.019202697e-07;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  byte numDigits = 4; // sets the no. of digits on my display
  byte digitPins[] = {10, 11, 12, 13}; // Creates an array that defines the groun dpins when using a 4 digit or multi-digit display. this is a single digit so no need to insert anything
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4}; // Declares an array that defines which arduino pins are connected to each segment of the display. Order is A, B, C, D, E, F, G, DP
  bool resistorsOnSegments = true; // Set to true if the  resistor is in series with the common cathod pines

  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; // they type of single-digit 7-segment display in use
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90); // set brightness (0 - 100)

}

void loop() {
  // put your main code here, to run repeatedly:

  // sevseg.setNumber(4999, 2); // Prints number to display
  // sevseg.refreshDisplay(); // Required at the end of the loop to continue displaying the number

  // for (int i = 0; i < 10; i++ ) {
  //   sevseg.setNumber(i, i % 2);
  //   delay(1000);
  //   sevseg.refreshDisplay();
  // }
  // for (int i = 0; i < 10; i++) {
  //   if (i % 2 != 0) {
  //     sevseg.setNumber(i, 0);
  //     delay(1000);
  //     sevseg.refreshDisplay();
  //   } else {
  //     sevseg.setNumber(i);
  //     delay(1000);
  //     sevseg.refreshDisplay();
  //   }
  // }

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  T = T - 273.15;
  T = (T * 9.0) / 5.0 + 32.0;

  static unsigned long timer = millis();

  if (millis() >= timer) {
    timer += 300;
    sevseg.setNumber(T, 2);
  }

  sevseg.refreshDisplay();

  

}
