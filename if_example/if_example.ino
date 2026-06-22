

void setup() {
  // put your setup code here, to run once:
  // int variableOne = 8;
  // int variableTwo = 8;
  Serial.begin(9600);
  bool myBool = false;

  Serial.println();
  Serial.println("This line should print irrespective of anything.");
  Serial.println();

  if (true) {
    Serial.println("This is nested if");
    if (false) {
      Serial.println("This is another line which will not execute.");
    }
  }

  if (2<5 || 5>2) {
    Serial.println("This statement will not print as the condition is false.");
  }

  Serial.println("This line should also print irrespective of anything.");

 
}

void loop() {
  // 
  // static int xyz = 0;
  // xyz++;
  // Serial.println(xyz);
  // // Serial.println("hi");
  // delay(500);
}
