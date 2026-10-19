#include <IRremoteESP8266.h>
#include <IRrecv.h>

IRrecv irrecv(15);
decode_results results; 
const int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0xFF30CF) {
      digitalWrite(ledPin, HIGH);
    } else if (results.value == 0xFF18E7) {
      digitalWrite(ledPin, LOW);
    }
    delay(100);
    irrecv.resume();
  }

  // if (irrecv.decode(&results)) {
  //   Serial.println(results.value, HEX);
  // } 
  // else {
  //   Serial.println("No signal...");
  // }

  // if (results.value == 0xFF30CF) {
  //   digitalWrite(ledPin, HIGH);
  // } else if (results.value == 0xFF18E7) {
  //   digitalWrite(ledPin, LOW);
  // }
  // delay(100);
  // irrecv.resume();

}
