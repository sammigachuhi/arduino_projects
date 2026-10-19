// #include <Arduino.h>
// #include <IRremoteESP8266.h>
// #include <IRutils.h>
// #include <IRrecv.h>
// #include <ESP32Servo.h>

// Servo myservo;

// const int servoPin = 18;
// const uint16_t IR_RECEIVE_PIN = 14;

// IRrecv irrecv(IR_RECEIVE_PIN);
// decode_results results;

// // Prototype with uint64_t to prevent sign-extension bugs
// String decodeKeyValue(uint64_t result);

// void setup() {
//   Serial.begin(115200);

//   // Start the IR receiver
//   irrecv.enableIRIn();

//   // Configure Servo with ESP32 PWM allocation
//   ESP32PWM::allocateTimer(0);
//   ESP32PWM::allocateTimer(1);
//   ESP32PWM::allocateTimer(2);
//   ESP32PWM::allocateTimer(3);
  
//   myservo.setPeriodHertz(50);          // Standard 50Hz servo
//   myservo.attach(servoPin, 500, 2400); // Attach servo to pin 18
//   myservo.write(0);                    // Set initial position to 0 degrees

//   Serial.println("System Ready. Press '0' on remote...");
// }

// void loop() {
//   if (irrecv.decode(&results)) {
//     // Print raw value to Serial Monitor for troubleshooting
//     Serial.print("Received Hex: 0x");
//     serialPrintUint64(results.value, HEX);
//     Serial.println();

//     String key = decodeKeyValue(results.value);

//     if (key == "0") {
//       Serial.println("Key 0 pressed! Moving servo to 90 degrees...");
      
//       // Direct move to 90 degrees
//       myservo.write(90); 
//     } 
//     else if (key == "POWER") {
//       Serial.println("Power pressed! Resetting servo to 0 degrees...");
//       myservo.write(0);
//     }

//     // Resume receiving IR signals
//     irrecv.resume(); 
//   }
// }

// // Fixed function signature using uint64_t
// String decodeKeyValue(uint64_t result) {
//   switch (result) {
//     case 0xFF6897: return "0";
//     case 0xFF30CF: return "1";
//     case 0xFF18E7: return "2";
//     case 0xFF7A85: return "3";
//     case 0xFF10EF: return "4";
//     case 0xFF38C7: return "5";
//     case 0xFF5AA5: return "6";
//     case 0xFF42BD: return "7";
//     case 0xFF4AB5: return "8";
//     case 0xFF52AD: return "9";
//     case 0xFF906F: return "+";
//     case 0xFFA857: return "-";
//     case 0xFFE01F: return "EQ";
//     case 0xFFB04F: return "U/SD";
//     case 0xFF9867: return "CYCLE";
//     case 0xFF22DD: return "PLAY/PAUSE";
//     case 0xFF02FD: return "BACKWARD";
//     case 0xFFC23D: return "FORWARD";
//     case 0xFFA25D: return "POWER";
//     case 0xFFE21D: return "MUTE";
//     case 0xFF629D: return "MODE";
//     default:       return "ERROR";
//   }
// }


//////////////////////////////////////////////////////
#include <Arduino.h>
#include <ESP32Servo.h>

Servo testServo;
const int servoPin = 13; // Try 13 or 4 if 18 doesn't respond

void setup() {
  Serial.begin(115200);
  
  // Attach servo with standard 500-2400us pulse width
  testServo.attach(servoPin, 500, 2400);
  Serial.println("Testing Servo Motor...");
}

void loop() {
  Serial.println("Moving to 90 degrees");
  testServo.write(90);
  delay(2000);

  Serial.println("Moving to 0 degrees");
  testServo.write(0);
  delay(2000);
}



