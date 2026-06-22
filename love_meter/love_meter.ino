#include "DHT.h"

#define DHTPIN A0

#define DHTTYPE DHT11 
// #define DHTTYPE DHT22
// #define DHTTYPE DHT21

DHT dht(DHTPIN, DHTTYPE);

const int sensorPin = A0;
const float baselineTemp = 18.0;


void setup() {
  Serial.begin(9600); 

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  dht.begin();
  
}


void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Convert the ADC reading to voltage 
  float voltage = sensorVal * (5.0 / 1023.0);  // (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  // Convert the voltage to a temperature in degrees 
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println(temperature);

  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1000);

}




