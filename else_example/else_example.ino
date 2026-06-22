int temperature = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  {
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
  }
  
 
}

void loop() {
  // 
  if (temperature <= 50 && temperature >= 10) {
    // do Thing A 
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
  } else if (temperature > 50 && temperature <= 70) {
    // do Thing B 
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
    delay(500);
  } else {
    // do Thing C 
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
  }
  
}
