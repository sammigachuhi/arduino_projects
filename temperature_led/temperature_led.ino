//////////////////////////////////
// LED
#include "SevSeg.h"
SevSeg sevseg; 

////////////////////////////
// Temperature 
#include <DHT.h>

#define DHTTYPE DHT11 

#define DHTPIN A0

DHT dht(DHTPIN, DHTTYPE);


void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);

  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  ///////////////////////////////
  // Temperature 
  dht.begin();
}

void loop(){

    float t = dht.readTemperature();
    float h = dht.readHumidity();
    float hic = dht.computeHeatIndex(t, h, false);
    
    // In case of failure
    if(isnan(t)) {
      Serial.println("Failed to read from DHT sensor");
    } else {
      // Serial.println(t);
      // Serial.print(h);
      // Serial.print(hic);
      // Serial.println();
    }

    sevseg.setNumber(t);
    sevseg.refreshDisplay(); 
    // delay(1000);
    // sevseg.setNumber(h);
    // sevseg.refreshDisplay(); 

    
}
