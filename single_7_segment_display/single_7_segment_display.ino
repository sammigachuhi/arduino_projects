#include "SevSeg.h"
SevSeg sevseg; // Create sevseg object

void setup() {
  // put your setup code here, to run once:

  byte numDigits = 1; // sets the no. of digits on my display
  byte digitPins[] = {}; // Creates an array that defines the groun dpins when using a 4 digit or multi-digit display. this is a single digit so no need to insert anything
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9}; // Declares an array that defines which arduino pins are connected to each segment of the display. Order is A, B, C, D, E, F, G, DP
  bool resistorsOnSegments = true; // Set to true if the  resistor is in series with the common cathod pines

  byte hardwareConfig = COMMON_CATHODE; // they type of single-digit 7-segment display in use
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(100); // set brightness (0 - 100)

}

void loop() {
  // put your main code here, to run repeatedly:

  // sevseg.setNumber(4, 0); // Prints number to display
  // sevseg.refreshDisplay(); // Required at the end of the loop to continue displaying the number

  // for (int i = 0; i < 10; i++ ) {
  //   sevseg.setNumber(i, i % 2);
  //   delay(1000);
  //   sevseg.refreshDisplay();
  // }
  for (int i = 0; i < 10; i++) {
    if (i % 2 != 0) {
      sevseg.setNumber(i, 0);
      delay(1000);
      sevseg.refreshDisplay();
    } else {
      sevseg.setNumber(i);
      delay(1000);
      sevseg.refreshDisplay();
    }
  }

}
