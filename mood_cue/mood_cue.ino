#include <Servo.h> // download servo library

Servo myservo; // creates servo object to control a servo

int val; // variable to read the value from the analog pin

int potVal;
int angle;

int const pin = A1;
void setup() {
  Serial.begin(9600);
  myservo.attach(9); // ensure output to servo on pin 9
}

void loop() {
  Serial.println("The A1 pin value: ");
  potVal = analogRead(pin); // reads the value of the potentiometer from A1 (a value between 0 and 1023)
  Serial.println(potVal);
  angle = map(potVal, 0, 1023, 0, 180);
  Serial.println("The servor angle: ");
  Serial.println(angle);
  myservo.write(angle); // sets the servo postion according to the input from the potentiometer 
  delay(15);
}





