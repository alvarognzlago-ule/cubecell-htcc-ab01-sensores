#include <Wire.h>
#include <BH1750.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Configuración WiFi
const char* ssid = "OpenWrt";
const char* password = "r1712017";

// Configuración MQTT
const char* mqtt_server = "192.168.1.122";
const int mqtt_port = 1883;

// BH1750
BH1750 lightMeter;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32-LUZ")) {
      Serial.println("Conectado al broker MQTT");
    } else {
      Serial.print("Fallo conexión MQTT, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // Asegúrate que son los pines correctos

  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("BH1750 iniciado correctamente");
  } else {
    Serial.println("Error iniciando BH1750");
  }

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  float lux = lightMeter.readLightLevel();

  Serial.print("Luminosidad: ");
  Serial.print(lux);
  Serial.println(" lux");

  char payload[64];
  snprintf(payload, sizeof(payload), "{\"luminosidad\":%.2f}", lux);
  client.publish("sensor/luz", payload);

  delay(10000); // Envía cada 10 segundos
}
