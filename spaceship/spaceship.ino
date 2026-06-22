int switchState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  switchState = digitalRead(2);
  //
  if (switchState == LOW) {
    // the button is not pressed 
    digitalWrite(3, HIGH); // green LED
    // Serial.println("Green LED on");
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, LOW); // red LED
  } else {
    // the button is pressed 
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    // Serial.println("Red LED on pin 5 on.");

    delay(250); // wait for a quarter second 
    // toggle the LEDs
    digitalWrite(4, HIGH);
    // Serial.println("Red light on pin 4 on.");
    digitalWrite(5, LOW);
    delay(250); // wait for a quarter second

  }

  /// Print status of switch
  // if (switchState == 0) {
  //   Serial.println("The switch is off...");
  // } else {
  //   Serial.println("The switch is on....");
  // }
}



