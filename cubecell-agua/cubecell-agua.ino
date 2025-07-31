#include <OneWire.h>
#include <DallasTemperature.h>

#define WATER_TEMP_PIN GPIO1   // DS18B20
#define ANALOG_PIN GPIO2       // Entrada analógica
#define TDS_VCC_PIN GPIO3      // Alimentación TDS
#define PH_VCC_PIN  GPIO4      // Alimentación pH

OneWire oneWire(WATER_TEMP_PIN);
DallasTemperature sensors(&oneWire);

float aref = 3.3;
float adcRange = 4095.0;

float readSensor(int vccPin, float tempC, bool isTDS) {
  // Encender el sensor
  digitalWrite(vccPin, HIGH);
  delay(500); // esperar estabilización

  int raw = analogRead(ANALOG_PIN);
  float voltage = (raw / adcRange) * aref;

  // Apagar el sensor
  digitalWrite(vccPin, LOW);

  if (isTDS) {
    // Fórmula aproximada para TDS
    return voltage * 133.42 / (1.0 + 0.02 * (tempC - 25.0));
  } else {
    // pH lineal aproximado (ajustar con calibración)
    return (voltage * 3.5); 
  }
}

void setup() {
  Serial.begin(115200);
  sensors.begin();

  pinMode(TDS_VCC_PIN, OUTPUT);
  pinMode(PH_VCC_PIN, OUTPUT);
  digitalWrite(TDS_VCC_PIN, LOW);
  digitalWrite(PH_VCC_PIN, LOW);

  Serial.println("Iniciando sensores...");
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: no se detecta el sensor de temperatura.");
    tempC = 25.0; // valor por defecto
  }

  // Leer TDS
  float tdsValue = readSensor(TDS_VCC_PIN, tempC, true);
  Serial.print("TDS aprox: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");

  // Leer pH
  float phValue = readSensor(PH_VCC_PIN, tempC, false);
  Serial.print("pH aprox: ");
  Serial.println(phValue);

  Serial.println("--------------------");
  delay(2000);
}
