// void setup() {
//   Serial.begin(115200);
//   delay(1000);
//   Serial.println("\nESP32 is alive and working!");
// }

// void loop() {
//   Serial.println("Tick...Tock");
//   delay(1000);
// }

// Most ESP32 dev boards use GPIO 2 for the built-in LED
// const int ledPin = 2; 

// void setup() {
//   pinMode(ledPin, OUTPUT);
// }

// void loop() {
//   digitalWrite(ledPin, HIGH); // Turn LED ON
//   delay(500);                 // Wait for half a second
//   digitalWrite(ledPin, LOW);  // Turn LED OFF
//   delay(500);                 // Wait for half a second
// }


/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-led-blink
 */
int ledPin = 18;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin GPIO18 as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH); // turn the LED on
  delay(500);             // wait for 500 milliseconds
  digitalWrite(ledPin, LOW);  // turn the LED off
  delay(500);             // wait for 500 milliseconds
}
