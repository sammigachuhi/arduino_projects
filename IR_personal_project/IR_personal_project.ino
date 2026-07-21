#include <IRremote.h>
#include <LiquidCrystal.h>

// LED pins
int redLED = A0; //12;
int yellowLED = A1;
int greenLED = A2;

// Value to control lighting
int value;

// IRrecv IR(2);
const byte IR_RECEIVE_PIN = 6;

// Piezometer pin
int piezometerPin = 4;
// First test making noise using piezometer

/// LCD Display 
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(piezometerPin, OUTPUT);

  ///
  Serial.println();
  Serial.println("-------------Infrared reciever decoded values-------------");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  // LCD 
  lcd.begin(16, 2);
  // Print a message to LCD

}

void loop() {
  // put your main code here, to run repeatedly:
  // Solution: https://forum.arduino.cc/t/ir-receiver-issues-in-the-serial-monitor/696792/2

  bool isRedOn = analogRead(redLED);
  bool isYellowOn = analogRead(yellowLED);
  bool isGreenOn = analogRead(greenLED);

  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command);
    value = IrReceiver.decodedIRData.command;

    // tun on the lightbulbs
    if (value == 12 || value == 24) { // turn on red light
      analogWrite(redLED, 255);
      analogWrite(yellowLED, 0);
      analogWrite(greenLED, 0);
    } else if (value == 94 || value == 8) { // turn on yel0 light
      analogWrite(redLED, 0);
      analogWrite(yellowLED, 255);
      analogWrite(greenLED, 0);
    } else if (value == 28 || value == 90) { // turn on green light
      analogWrite(redLED, 0);
      analogWrite(yellowLED, 0);
      analogWrite(greenLED, 255);
    } else if (value == 66) {
      analogWrite(redLED, 255);
      analogWrite(yellowLED, 255);
      analogWrite(greenLED, 0);
    } else if (value == 82) {
      analogWrite(redLED, 0);
      analogWrite(yellowLED, 255);
      analogWrite(greenLED, 255);
    } else if (value == 74) {
      analogWrite(redLED, 0);
      delay(100);
      analogWrite(redLED, 255);
      delay(100);
      analogWrite(yellowLED, 0);
      delay(100);
      analogWrite(yellowLED, 255);
      delay(100);
      analogWrite(greenLED, 0);
      delay(100);
      analogWrite(greenLED, 255);
      delay(100);

      /////
      analogWrite(redLED, 0);
      delay(100);
      analogWrite(redLED, 255);
      delay(100);
      analogWrite(yellowLED, 0);
      delay(100);
      analogWrite(yellowLED, 255);
      delay(100);
      analogWrite(greenLED, 0);
      delay(100);
      analogWrite(greenLED, 255);
      delay(500);
    } 

    delay(500);
    IrReceiver.resume();
  }

  /// Print lcd
  if (isRedOn == true && (!isYellowOn && !isGreenOn)) {
    lcd.print("STOP!");
    delay(500);
    lcd.clear();
  } else if (isYellowOn == true && (!isRedOn && !isGreenOn)) {
    lcd.print("GET READY!");
    delay(500);
    lcd.clear();
  } else if (isGreenOn == true && (!isRedOn && !isYellowOn)) {
    lcd.print("MOVE!");
    delay(500);
    lcd.clear();
  } else if ( (isRedOn && isYellowOn) && (!isGreenOn) ) {
    lcd.print("ON THE READY!");
    delay(500);
    lcd.clear();
  } else if ( (isYellowOn && isGreenOn) && (!isRedOn) ) {
    lcd.print("ALL CLEAR, MOVE!");
    delay(500);
    lcd.clear();
  } else if ( (isRedOn && isYellowOn && isGreenOn) ) {
    lcd.print("SYSTEM ERROR...");
    delay(500);
    lcd.clear();
  }

}
