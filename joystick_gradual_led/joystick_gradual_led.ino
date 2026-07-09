int LEDYellow = 11; // Yellow Pin
int LEDRed = 10; // Red Pin

// Joystick variables
int xPin = A0;
int yPin = A1;
int buttonPin = 2;
int xVal;
int yVal;

int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(LEDYellow, OUTPUT);
  pinMode(LEDRed, OUTPUT);
  
  // Check joystick controls
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  ///// Print joystick status
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  double averageValue = (xVal + yVal) / 2;
  int yellowBrightness = map(averageValue, 0, 499, 0, 255);
  int redBrightness = map(averageValue, 500, 1023, 0, 255);

  // Joystick control over LED
  if (buttonState == 0) {
    analogWrite(LEDYellow, 255);
    analogWrite(LEDRed, 255);
  } else if ( averageValue < 500 ) {
    analogWrite(LEDYellow, yellowBrightness);
    analogWrite(LEDRed, 0);
    // delay(500);
  } else if ( averageValue >= 500 ) {
    analogWrite(LEDRed, redBrightness);
    analogWrite(LEDYellow, 0);
    // delay(500);
  } 

  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Average value: ");
  Serial.print(averageValue);
  Serial.print(" | Yellow Brightness: ");
  Serial.print(yellowBrightness);
  Serial.print(" | Red Brightness: ");
  Serial.print(redBrightness);
  
  Serial.print(" | Switch: ");
  Serial.println(buttonState);

  delay(500);

}
