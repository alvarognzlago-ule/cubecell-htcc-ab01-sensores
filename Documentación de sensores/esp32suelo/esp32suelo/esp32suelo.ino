#define HUMEDAD_PIN 35  // Pin ADC conectado a AO

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // Rango 0-4095
}

void loop() {
  int valorHumedad = analogRead(HUMEDAD_PIN);
  float voltaje = valorHumedad * 3.3 / 4095.0;

  Serial.print("Lectura ADC: ");
  Serial.print(valorHumedad);
  Serial.print(" - Voltaje: ");
  Serial.print(voltaje, 2);
  Serial.println(" V");

  delay(1000);
}
