/*
 * Project Webhooks
 * Description:
 * Author: Ashley Whamond
 * Date: 16/04/22
 */
#include <Grove_Temperature_And_Humidity_Sensor.h>

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
  

  // Check if any reads failed
  if (isnan(h) || isnan(t))
  {
    Particle.publish("Failed to read from DHT11 sensor!");
    return;
  }

  Particle.publish("Humidity:", String(h));
  Particle.publish("Temp:", String(t));
}