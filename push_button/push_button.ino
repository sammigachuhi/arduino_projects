
int button = 7;

// int LED_BUILTIN = 13;
int pinValue = 13;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(pinValue, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // 
  Serial.println(digitalRead(button));

  if (digitalRead(button) == HIGH) {

    digitalWrite(pinValue, HIGH);
  } else {
    digitalWrite(pinValue, LOW);
  }
  
}


