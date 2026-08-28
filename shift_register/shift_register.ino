// ST_CP pin 12
const int latchPin = 5; 
// SH_CP pin 11 
const int clockPin = 6; 
// DS pin 14 
const int dataPin = 4;

// Variable to hold the pattern of which LEDs are currently on or off
byte leds = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // leds = 0;  // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  // updateShiftRegister();
  // delay(500);
  // for (int i = 0; i < 8; i++)  // Turn all the LEDs ON one by one.
  // {
  //   bitSet(leds, i);  // Set the bit that controls that LED in the variable 'leds'
  //   updateShiftRegister();
  //   delay(500);
  // }


  ///////////////////////////////////////////////////////////
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
 
    // ST_CP LOW to keep LEDs from changing while reading serial data
    digitalWrite(latchPin, LOW);
 
    // Shift out the bits
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
 
    // ST_CP HIGH change LEDs
    digitalWrite(latchPin, HIGH);
 
    delay(500);
  }

}

// /*
//  This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
//  */
// void updateShiftRegister() {
//   digitalWrite(latchPin, LOW);
//   shiftOut(dataPin, clockPin, LSBFIRST, leds);
//   digitalWrite(latchPin, HIGH);
// }
