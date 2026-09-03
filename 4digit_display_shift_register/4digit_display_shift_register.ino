
int latch = 9;
int clock = 10;
int data = 8;

int d3 = 4;
int d2 = 2;

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};


void Display(unsigned char num);


void setup() {
  // put your setup code here, to run once:
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  int start = 0;
  int end = 10;
  for (i = start; i < end; i++) {
    Display(i);
    delay(500);
  }

}


void Display(unsigned char num) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
}