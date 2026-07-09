#define LED_PIN 11
#define POTENTIOMETER_PIN A2

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  Serial.println();
  Serial.print("Potentiometer value: ");
  Serial.print(potentiometerValue);
  int brightness = map(potentiometerValue, 0, 1023, 0, 255);
  Serial.print(" Brightness value: ");
  Serial.print(brightness);
  analogWrite(LED_PIN, brightness);
  delay(1000);
}




