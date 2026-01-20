/***
Example Code for DHT11 sensor
***/

#include "DHTStable.h"

DHTStable DHT;

int DHT11_PIN = 5;

void setup()
{
  Serial.begin(9600);
}

void loop()
{ 
  // read sensor
  DHT.read11(DHT11_PIN);
  //  DISPLAY DATA
  Serial.print("Temperature:");
  Serial.print(DHT.getTemperature(), 1); // one decimal
  Serial.print("C");
  Serial.print(",\t");
  Serial.print("Humidity:");
  Serial.println(DHT.getHumidity(), 1);
  delay(2000);
}