

void setup() {
  // put your setup code here, to run once:
  // int variableOne = 8;
  // int variableTwo = 8;
  Serial.begin(9600);
  Serial.println("The lessons about && operator");
  Serial.println("true and true is :");
  Serial.println(5>3&&7<8);
  Serial.println("true and false is :");
  Serial.println(true&&8<5);
  Serial.println("false and t rue is :");
  Serial.println(false&&true);
  Serial.println("false a n false is : ");
  Serial.println(5<2||4>9);
  // Serial.println(xyz);

  Serial.println();
  Serial.println();
  Serial.println();

  Serial.println("The lesson is about || operator");

  Serial.println("true or true is :");
  Serial.println(true||true);
  Serial.println("true or false :");
  Serial.println(true||false);
  Serial.println("false or true is :");
  Serial.println(false||true);
  Serial.println("false or false :");
  Serial.println(false||false);

  Serial.println();
  Serial.println();
  Serial.println();

  Serial.println("The lesson is about ! operator");
  Serial.println("The not of true is :");
  Serial.println(!true);
  Serial.println("The not of false is : ");
  Serial.println(!false);

 
}

void loop() {
  // 
  // static int xyz = 0;
  // xyz++;
  // Serial.println(xyz);
  // // Serial.println("hi");
  // delay(500);
}
