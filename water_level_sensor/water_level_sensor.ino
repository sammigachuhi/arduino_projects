#define ledPin 6
#define sensorPin A0



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
  int outputValue = map(sensorValue, 420, 500, 0, 255);

  if (sensorValue < 420) {
    // int outputValue = map(sensorValue, 570, 800, 0, 255);
    // Serial.println(outputValue);
    analogWrite(ledPin, 0);
  } else if (sensorValue >= 420) {
    analogWrite(ledPin, outputValue);
  }

  Serial.println();
  Serial.print("Sensor value: | ");
  Serial.print(sensorValue);
  Serial.print(" | Brightness value: | ");
  Serial.print(outputValue);
  // Serial.println();
  // Serial.print("Water Sensor Value | ");
  // Serial.print(sensorValue);
  // Serial.print(" | Brightness value | ");
  // Serial.print(outputValue);
  delay(500);
  
}


