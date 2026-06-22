void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  int myArray [5] = { 745, 74, 259, 65, 421 };

  Serial.println(myArray[2]);

  myArray[2] = 706;

  Serial.println(myArray[2]);
}

void loop() {
  // 

}
