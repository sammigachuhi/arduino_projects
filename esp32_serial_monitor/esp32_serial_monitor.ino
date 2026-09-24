int ledPin = 2;
String cmd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Serial.println("Hello ESP32");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    cmd = Serial.readString();
    if (cmd == "on") {
      digitalWrite(ledPin, HIGH);
    } else if (cmd == "off") {
      digitalWrite(ledPin, LOW);
    }
  }
}
