#include <IRremote.h>
#include <LiquidCrystal.h>

// LED pins
int redLED = A0; //12;
int yelLED = A1;
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
  pinMode(yelLED, OUTPUT);
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

  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command);
    value = IrReceiver.decodedIRData.command;

    // tun on the lightbulbs
    if (value == 12 || value == 24) { // turn on red light
      analogWrite(redLED, 255);
      analogWrite(yelLED, 0);
      analogWrite(greenLED, 0);
      lcd.print("STOP!");
      delay(1500);
      lcd.clear();
      // delay(500);

    } else if (value == 94 || value == 8) { // turn on yel0 light
      analogWrite(redLED, 0);
      analogWrite(yelLED, 255);
      analogWrite(greenLED, 0);
      // Print LCD 
      lcd.print("GET READY!");
      delay(1500);
      lcd.clear();
      // delay(500);
    } else if (value == 28 || value == 90) { // turn on green light
      analogWrite(redLED, 0);
      analogWrite(yelLED, 0);
      analogWrite(greenLED, 255);
      // Print LCD 
      lcd.print("MOVE!");
      delay(1500);
      lcd.clear();
    } else if (value == 66) {
      analogWrite(redLED, 255);
      analogWrite(yelLED, 255);
      analogWrite(greenLED, 0);
      lcd.print("ON THE READY!");
      delay(1500);
      lcd.clear();
    } else if (value == 82) {
      analogWrite(redLED, 0);
      analogWrite(yelLED, 255);
      analogWrite(greenLED, 255);
      // Print LED 
      lcd.print("ALMOST!");
      delay(1500);
      lcd.clear();
    } else if (value == 74) {
      analogWrite(redLED, 0);
      delay(100);
      analogWrite(redLED, 255);
      delay(100);
      analogWrite(yelLED, 0);
      delay(100);
      analogWrite(yelLED, 255);
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
      analogWrite(yelLED, 0);
      delay(100);
      analogWrite(yelLED, 255);
      delay(100);
      analogWrite(greenLED, 0);
      delay(100);
      analogWrite(greenLED, 255);
      delay(500);
      /// Print LCD
      lcd.print("ALL CLEAR!");
      delay(1500);
      lcd.clear();
    } 

    delay(500);
    IrReceiver.resume();
  }


}
