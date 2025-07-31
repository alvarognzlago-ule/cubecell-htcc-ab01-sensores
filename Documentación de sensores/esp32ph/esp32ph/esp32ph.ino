#define PH_PIN 34

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // Rango 0-4095 en ESP32
}

void loop() {
  int lecturaADC = analogRead(PH_PIN);
  float voltaje = (lecturaADC * 3.3) / 4095.0;

  // Fórmula básica (sin calibración)
  float pH = 7 + (2.5 - voltaje) / 0.18;

  Serial.print("ADC: ");
  Serial.print(lecturaADC);
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje, 3);
  Serial.print(" V | pH: ");
  Serial.println(pH, 2);

  delay(1000);
}
