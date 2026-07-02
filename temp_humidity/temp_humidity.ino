#include <dht.h>
#include <LiquidCrystal.h>

// Step-by-Step Wiring (No Potentiometer)

// Wire your LCD to your Arduino exactly like this:

//     VSS (Pin 1) ➡️ Arduino GND

//     VDD (Pin 2) ➡️ Arduino 5V

//     V0 (Pin 3) ➡️ Connect to GND (either directly or through a 1k-ohm resistor)

//     RS (Pin 4) ➡️ Arduino Digital Pin 12

//     RW (Pin 5) ➡️ Arduino GND

//     E (Pin 6) ➡️ Arduino Digital Pin 11

//     Pins 7, 8, 9, 10 remain completely empty

//     D4 (Pin 11) ➡️ Arduino Digital Pin 5

//     D5 (Pin 12) ➡️ Arduino Digital Pin 4

//     D6 (Pin 13) ➡️ Arduino Digital Pin 3

//     D7 (Pin 14) ➡️ Arduino Digital Pin 2

//     A (Pin 15) ➡️ Arduino 5V (Put a 220-ohm resistor here so you don't burn out the backlight)

//     K (Pin 16) ➡️ Arduino GND

dht DHT;

#define DHT11_PIN 7

double temperature;
double humidity;

// Initialize LCD 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("System loading...");
  delay(1500);
  lcd.clear();


}

void loop() {
  int checkReadings = DHT.read11(DHT11_PIN);
  temperature = DHT.temperature;
  Serial.println("Temperature (degrees celsius): ");
  Serial.println(temperature);

  humidity = DHT.humidity;
  Serial.println("Humidity: ");
  Serial.println(humidity);
  delay(1000);

  /////////////////////////////////
  /// Print to LCD ///////////
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp (C): ");
  lcd.print(temperature);

  lcd.setCursor(0, 1);
  lcd.print("Humidity (%): ");
  lcd.print(humidity);
  delay(4000);
  lcd.clear();
  delay(50);


}


