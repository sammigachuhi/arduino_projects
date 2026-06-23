int photoResistorPin = A0;
int pin1 = 2;
int darknessValue = 11;

/////// RGB pins
int redPin = 8; // 11;
int greenPin = 7; // 10;
int bluePin = 4; // 9;


// first read photoResistor values -- check
// now get the output pin for your bulb

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);

  // Defining the pins as OUTPUT 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void loop() {

  int photoResistorLight = analogRead(photoResistorPin);
  // Serial.println("============Photoresistor readings:==============");
  Serial.println(photoResistorLight);
  delay(100);

  if (photoResistorLight < darknessValue) {
    digitalWrite(pin1, HIGH);
    // Serial.println("LED IS ON");

    //////// RGB lights sequence
    setColor(255, 0, 0); // Red
    delay(1000);
    setColor(0, 255, 0); // Green
    delay(1000);
    setColor(0, 0, 255); // Blue
    delay(1000);
    setColor(255, 255, 0); // Yellow
    delay(1000);
    setColor(0, 255, 255); // Cyan
    delay(1000);
    setColor(255, 0, 255); // Magenta
    delay(1000);
    setColor(255, 165, 0); // Orange
    delay(1000);
    setColor(128, 0, 128); // Purple
    delay(1000);
    setColor(255, 255, 255); // White
    delay(1000);

  } else {
    digitalWrite(pin1, LOW);
  }

}

void setColor(int redValue, int greenValue, int blueValue) {
  digitalWrite(redPin, redValue);
  digitalWrite(greenPin, greenValue);
  digitalWrite(bluePin, blueValue);
}

