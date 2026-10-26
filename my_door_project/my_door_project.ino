#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(21, 22, 18, 19, 23, 5); 

#define IR_PIN 14

#define PIN_RED    25 // GPIO23
#define PIN_GREEN  26 // GPIO22
#define PIN_BLUE   27 // GPIO21

void myColors(int val1, int val2, int val3);

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Hello, Samuel");
  // lcd.setCursor(0, 1);
  // lcd.print("No I2C module");

  // IR 
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver ready");

  // LED pins 
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (IrReceiver.decode()) {
    Serial.print("Received IR code Hex: ");
    int value = IrReceiver.decodedIRData.command; 
    // Serial.println(IrReceiver.decodedIRData.command, HEX);
    Serial.println(value, HEX);

    lcd.clear();
    lcd.setCursor(0, 0);

    switch(value) {
      case 0x16: 
        myColors(0, 255, 0);
        // lcd.clear();
        
        lcd.print("Opening...");
        lcd.cursor();
        break;

      case 0xC:
        myColors(255, 0, 0);
        lcd.print("Closing...");
        lcd.cursor();
        break;

      default:
        myColors(255, 255, 255);
        lcd.print("Unknown command...");
        // lcd.cursor();
        break;

    }

    IrReceiver.resume();
  }


}

void myColors(int val1, int val2, int val3) {
  analogWrite(PIN_RED, 255 - val1);
  analogWrite(PIN_GREEN, 255 - val2);
  analogWrite(PIN_BLUE, 255 - val3);
}
