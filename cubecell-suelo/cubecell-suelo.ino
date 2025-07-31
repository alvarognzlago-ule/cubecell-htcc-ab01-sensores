#include "DHT.h"

#define DHTPIN GPIO2       // Pin del DHT22
#define DHTTYPE DHT22      // Tipo de sensor
#define SOIL_PIN GPIO1     // Pin analógico para sensor resistivo

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Iniciando lectura DHT22 y sensor resistivo...");
}

void loop() {
  // Lectura del DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error leyendo DHT22");
  } else {
    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.print(" %  |  Temp: ");
    Serial.print(t);
    Serial.println(" °C");
  }

  // Lectura del sensor resistivo (0-4095 en CubeCell)
  int soilValue = analogRead(SOIL_PIN);
  Serial.print("Humedad del suelo (resistivo): ");
  Serial.println(soilValue);

  Serial.println("------------------------");
  delay(2000);
}
