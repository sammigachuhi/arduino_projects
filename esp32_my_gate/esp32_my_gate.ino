#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <ESP32Servo.h>

Servo myservo;

int pos = 0;

int servoPin = 18;

// define the IR receiver pin
const uint16_t IR_RECEIVE_PIN = 14;

// creat an IRrecv object
IRrecv irrecv(IR_RECEIVE_PIN);

// create a decode results object
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // start the IR receiver
  irrecv.enableIRIn();

  // servo
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
	// using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  // If an IR signal is received
  if (irrecv.decode(&results)) {

    String key = decodeKeyValue(results.value);
    // if (key != "ERROR") {
    //   // Print the value of the signal to the serial monitor
    //   Serial.println(key);
    // }
    if (key == "0") {
      Serial.println(key);
      pos = 90;
      myservo.write(pos);
      // delay(15);
      // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      //       // in steps of 1 degree
      //       myservo.write(pos);    // tell servo to go to position in variable 'pos'
      //       delay(15);             // waits 15ms for the servo to reach the position
      //     }
    }
    irrecv.resume();
  }

  
}

// Function to decode
String decodeKeyValue(long result) {
  switch (result) {
    case 0xFF6897:
      return "0";
    case 0xFF30CF:
      return "1";
    case 0xFF18E7:
      return "2";
    case 0xFF7A85:
      return "3";
    case 0xFF10EF:
      return "4";
    case 0xFF38C7:
      return "5";
    case 0xFF5AA5:
      return "6";
    case 0xFF42BD:
      return "7";
    case 0xFF4AB5:
      return "8";
    case 0xFF52AD:
      return "9";
    case 0xFF906F:
      return "+";
    case 0xFFA857:
      return "-";
    case 0xFFE01F:
      return "EQ";
    case 0xFFB04F:
      return "U/SD";
    case 0xFF9867:
      return "CYCLE";
    case 0xFF22DD:
      return "PLAY/PAUSE";
    case 0xFF02FD:
      return "BACKWARD";
    case 0xFFC23D:
      return "FORWARD";
    case 0xFFA25D:
      return "POWER";
    case 0xFFE21D:
      return "MUTE";
    case 0xFF629D:
      return "MODE";
    // case 0xFFFFFFFF:
    //   return "ERROR";
    default:
      return "ERROR";
  }
}
