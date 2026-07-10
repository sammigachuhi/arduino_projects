// LED variables
int redLED1 = 11;
int yellowLED1 = 10;
int greenLED1 = 9;

int redLED2 = 6;
int yellowLED2 = 5;
int greenLED2 = 3;

// joystick variables
int joystickButton = 2;
int xPin = A0;
int yPin = A1;
int xVal;
int yVal;

int buttonState;
double averageValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);

  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);

  // Joystick controls
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(joystickButton, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  
  // Read button state
  buttonState = digitalRead(joystickButton);

  // LED brightness levels
  averageValue = (xVal + yVal) / 2;
  int redBrightness = map(averageValue, 0, 341, 0, 255);
  int yellowBrightness = map(averageValue, 342, 684, 0, 255);
  int greenBrightness = map(averageValue, 685, 1023, 0, 255);

  if (buttonState == 0) {
    analogWrite(redLED1, 255);
    analogWrite(yellowLED1, 255);
    analogWrite(greenLED1, 255);
    analogWrite(redLED2, 255);
    analogWrite(yellowLED2, 255);
    analogWrite(greenLED2, 255);
  } else if (averageValue < 340) {
    analogWrite(redLED1, redBrightness);
    analogWrite(redLED2, redBrightness);
    analogWrite(yellowLED1, 0);
    analogWrite(yellowLED2, 0);
    analogWrite(greenLED1, 0);
    analogWrite(greenLED2, 0);
  } else if (averageValue < 684) {
    analogWrite(redLED1, 0);
    analogWrite(redLED2, 0);
    analogWrite(yellowLED1, yellowBrightness);
    analogWrite(yellowLED2, yellowBrightness);
    analogWrite(greenLED1, 0);
    analogWrite(greenLED2, 0);
  } else {
    analogWrite(redLED1, 0);
    analogWrite(redLED2, 0);
    analogWrite(yellowLED1, 0);
    analogWrite(yellowLED2, 0);
    analogWrite(greenLED1, greenBrightness);
    analogWrite(greenLED2, greenBrightness);
  }

  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Average value: ");
  Serial.print(averageValue);
  Serial.print(" | Red Brightness: ");
  Serial.print(redBrightness);
  Serial.print(" | Yellow Brightness: ");
  Serial.print(yellowBrightness);
  Serial.print(" | Green Brightness: ");
  Serial.print(greenBrightness);
  
  Serial.print(" | Switch: ");
  Serial.println(buttonState);

  delay(500);

}
