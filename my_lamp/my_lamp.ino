int photoResistorPin = A0;
int pin1 = 2;
int darknessValue = 11;

// first read photoResistor values -- check
// now get the output pin for your bulb

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
}

void loop() {

  int photoResistorLight = analogRead(photoResistorPin);
  // Serial.println("============Photoresistor readings:==============");
  Serial.println(photoResistorLight);
  delay(100);

  if (photoResistorLight < darknessValue) {
    digitalWrite(pin1, HIGH);
    // Serial.println("LED IS ON");
  } else {
    digitalWrite(pin1, LOW);
  }

}




