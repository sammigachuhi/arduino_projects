#include <Servo.h>

Servo myservo; // Create servo object to control a servo

int pos = 0; // variable to store the servo position

/////////////////////////////
// Sonar variables
long duration;
long distance;

const int trigPin = 10;
const int echoPin = 11;

//////////////////////////////
// Piezometer
int piezometerPin = 8;


///////////////////////////
// LED
int redLED = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9); // Attaches the servo on pin 9 to the servo object

  // Servo
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  /// LED
  pinMode(redLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //////////////////////////
  // // Servo
  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // In steps of 1 degree 
  //   myservo.write(pos); // Tell servo to go to position in variable 'pos'
  //   delay(15);  // wait 15ms for the servo to reach the position 
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos); // tell servo to position in variable 'pos'
  //   delay(15);          // waits 15ms for the servo to reach the position

  // }

  /////////////////////////////
  // Sonar 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  //////////////////////////////////
  // Piezometer
  if (distance >= 4 && distance < 10) {
    tone(piezometerPin, 2000, 100);
    digitalWrite(redLED, HIGH);
  } else if (distance >= 10 && distance < 20) {
    tone(piezometerPin, 1000, 500);
    digitalWrite(redLED, LOW);
  } else if (distance >= 20 && distance < 50) {
    tone(piezometerPin, 500, 500);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(redLED, LOW);
  }

  Serial.println();
  Serial.print("Distance in cm (estimate): ");
  Serial.print(distance);
}
