int xPin = A0;
int yPin = A1;
int buttonPin = 2;
int xVal; // Variable for storing joystick x values 
int yVal; // variable for storing joystick y values
// int switchState; // variable for storing joystick switch state
int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // read the x, y and joystick switch values
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  // Print readings to the serial monitor
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Switch: ");
  Serial.println(buttonState);

  delay(100);

}




