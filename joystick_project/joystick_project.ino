int LED13 = 13; // Yellow Pin
int LED12 = 12; // Red Pin

// Joystick variables
int xPin = A0;
int yPin = A1;
int buttonPin = 2;
int xVal;
int yVal;

int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(LED13, OUTPUT);
  pinMode(LED12, OUTPUT);
  
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

  // Joystick control over LED
  if (buttonState == 0) {
    digitalWrite(LED13, HIGH);
    digitalWrite(LED12, HIGH);
  } else if ( (xVal < 522 && yVal < 512) || (xVal >= 522 && yVal >= 512) ) {
    digitalWrite(LED13, HIGH);
    digitalWrite(LED12, LOW);
    // delay(500);
  } else if ( (xVal < 522 && yVal >= 512) || (xVal >= 522 && yVal < 512) ) {
    digitalWrite(LED12, HIGH);
    digitalWrite(LED13, LOW);
    // delay(500);
  } 

  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Switch: ");
  Serial.println(buttonState);

  delay(500);

}




