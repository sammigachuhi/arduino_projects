#include <ESP32Servo.h>

Servo myServo;
int servoPin = 8;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  // myServo.write(90);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int angle = Serial.parseInt();
    // int angle = 100;
    myServo.write(angle);
    Serial.println(angle);
  }
  
  delay(20);

}
