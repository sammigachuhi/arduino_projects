int ledPin = 10;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  
  
}

void loop() {
  // 
 for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
  analogWrite(ledPin, fadeValue);

  delay(70);
 }

 for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
  analogWrite(ledPin, fadeValue);

  delay(70);
 }
  
}


