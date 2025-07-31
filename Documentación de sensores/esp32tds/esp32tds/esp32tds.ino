#define TDS_PIN 34  // Pin ADC donde conectas el TDS

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // Resolución ADC del ESP32 (0-4095)
}

void loop() {
  int analogValue = analogRead(TDS_PIN);
  float voltage = analogValue * 3.3 / 4095.0;  // Convertimos el valor ADC a voltaje

  // Cálculo simple de TDS (necesita calibración en la vida real)
  float tdsValue = (133.42 * voltage * voltage * voltage 
                  - 255.86 * voltage * voltage 
                  + 857.39 * voltage) * 0.5;

  Serial.print("Lectura ADC: ");
  Serial.print(analogValue);
  Serial.print(" - Voltaje: ");
  Serial.print(voltage, 2);
  Serial.print(" V - TDS: ");
  Serial.print(tdsValue, 2);
  Serial.println(" ppm");

  delay(1000);
}
