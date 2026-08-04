#include "SevSeg.h"
SevSeg sevseg;

// 4-segment 7-digit display LED values
byte numDigits = 4;
byte digitPins[] = {10, 11, 12, 13};
byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

bool resistorsOnSegments = true;
bool updateWithDelaysIn = true;
byte hardwareConfig = COMMON_CATHODE;

// Photoresistor variables
const int photoResistor = A0;
float photoResistorValue;

// RGB LED pins
const int redLED = A1;
const int greenLED = A2;
const int blueLED = A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // 4-segment 7-digit LED display
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  // Photoresistor
  pinMode(photoResistor, INPUT);

  // LED outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

}

void loop() {

  /////////////////////////
  // Read Photoresistor's values
  photoResistorValue = analogRead(photoResistor);

  // put your main code here, to run repeatedly:
  // Serial.println(photoResistorValue);
  sevseg.setNumber(photoResistorValue, 0);
  sevseg.refreshDisplay();

  // Light up orange colour
  if (photoResistorValue < 18) {
    // Light up orange
    
    setColour(255, 165, 0);
    // delay(100);
  } else {
    setColour(0, 0, 0); // no colour
  }


}

void setColour(int redValue, int greenValue, int blueValue) {
  analogWrite(redLED, 255 - redValue);
  analogWrite(greenLED, 255 - greenValue);
  analogWrite(blueLED, 255 - blueValue);
}


