#include <SevSegShift.h>

// Define Shift Register pins connected to ESP32
const int shiftPinDS = 14;   // Data
const int shiftPinSHCP = 11; // Clock
const int shiftPinSTCP = 12;  // Latch

// Create shift register instance (1 shift register used)
SevSegShift sevseg(shiftPinDS, shiftPinSHCP, shiftPinSTCP, 1, true); 

void setup() {
  byte numDigits = 4;
  
  // Define which ESP32 pins control the 4 common anode digits
  // (Adjust these 4 pins based on how you wire your display's digit commons)
  byte digitPins[] = {23, 22, 21, 27}; 
  
  // Since segments are driven by Q0-Q7 of the 74HC595, we pass dummy/placeholder 
  // array configurations for segment pins as handled by the shift register library.
  byte segmentPins[] = {0, 1, 2, 3, 4, 5, 6, 7}; 

  bool resistorsOnSegments = true; // Set to true if resistors are on Q0-Q7 lines
  bool hardwareConfig = COMMON_CATHODE; // Crucial: Set to Common Anode!
  bool updateWithDelays = false;
  bool leadingZeros = false;
  bool disableDecPoint = false;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, 
               resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  // Display a number or counter
  sevseg.setNumber(1234); 
  
  // This must be called continuously and rapidly to multiplex the digits
  sevseg.refreshDisplay(); 
}
