// nurse_station.ino
// ESP32 Alert System for Nurse Station

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const char* mqtt_server = "192.168.1.100"; // IP of MQTT broker

WiFiClient espClient;
PubSubClient client(espClient);

#define LED_PIN 2  // GPIO pin for alert LED
#define BUZZER_PIN 4  // GPIO pin for buzzer

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle incoming MQTT messages for alerts
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (message == "ALERT") {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000, 1000);  // Alert sound
    delay(2000);
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe("alerts");
    } else {
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
