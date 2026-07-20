#include <IRremote.h>

// IRrecv IR(2);
const byte IR_RECEIVE_PIN = 3;
int ledPin = 8;

// Remote values
int onValue = 21;
int offValue = 7;

void setup() {
  Serial.begin(9600);
  // IR.enableIRIn();
  pinMode(ledPin, OUTPUT);
  Serial.println();
  Serial.println("----------values---------");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {

  //////////////////////////
  // Solution: https://forum.arduino.cc/t/ir-receiver-issues-in-the-serial-monitor/696792/2


  if (IrReceiver.decode()) {
    // unsigned long keycode = IrReceiver.decodedIRData.command;
    // Serial.println(keycode);
    Serial.println(IrReceiver.decodedIRData.command);
    if (IrReceiver.decodedIRData.command == onValue) {
      digitalWrite(ledPin, HIGH);
    } else if (IrReceiver.decodedIRData.command == offValue) {
      digitalWrite(ledPin, LOW);
    } 
  
  delay(500);
  IrReceiver.resume();
  }
  
}
