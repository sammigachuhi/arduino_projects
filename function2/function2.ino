

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // // 
  // int d = sum(7, 8, 9);
  // // Serial.println(d);

  // int e = sum(1, 2, 3);
  // // Serial.println(e);
  // // Serial.println(sum(4, 5, 6));

  // Serial.println(isTall(123));
  // Serial.println(isTall(20));
  
}

int sum(int a, int b, int c) {
  return a + b + c;
}

bool isTall(int height) {
  if (height > 100) {
    return true;
  } else {
    return false;
  }
}
