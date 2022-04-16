/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/ashkl/Desktop/Deakin_22/SIT_210/Week_3/Task3.1P/Webhooks/src/Webhooks.ino"
/*
 * Project Webhooks
 * Description:
 * Author: Ashley Whamond
 * Date: 16/04/22
 */
#include <Grove_Temperature_And_Humidity_Sensor.h>

void setup();
void loop();
#line 9 "c:/Users/ashkl/Desktop/Deakin_22/SIT_210/Week_3/Task3.1P/Webhooks/src/Webhooks.ino"
int dhtPin = D2;
DHT dht(dhtPin);

void setup()
{
  pinMode(dhtPin, INPUT);

  Serial.println("DHT11 Begin!!!");

  dht.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  delay(5000);

  // Read Humidity
  float h = dht.getHumidity();
  // Read temperature as Celsius
  float t = dht.getTempCelcius();
  // Read temperature as Farenheit
  float f = dht.getTempFarenheit();

  // Check if any reads failed
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Failed to read from DHT11 sensor!");
    Particle.publish("Failed to read from DHT11 sensor!");
    return;
  }

  Serial.print("Humid: ");
  Serial.print(h);
  Serial.println("%  ");
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println("*C ");
  Serial.print("Temp: ");
  Serial.print(f);
  Serial.println();
  Serial.println();

  Particle.publish("Humidity:", String(h));
  Particle.publish("Temp:", String(t));
}