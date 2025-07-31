#include <OneWire.h>
#include <DallasTemperature.h>

// Definimos el pin de datos
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000);
}
