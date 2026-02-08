// csi_rx.ino
// ESP32 CSI Receiver

#include <WiFi.h>
#include <esp_wifi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const char* udpAddress = "192.168.1.100"; // IP of the backend
const int udpPort = 5005;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.println("Connected to WiFi");

  udp.begin(udpPort);

  // Initialize CSI
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&csi_callback);
}

void csi_callback(void* buf, wifi_promiscuous_pkt_type_t type) {
  // Capture and process CSI data
  // Placeholder: Send dummy CSI data via UDP
  uint8_t data[1024] = {0}; // Dummy data
  udp.beginPacket(udpAddress, udpPort);
  udp.write(data, sizeof(data));
  udp.endPacket();
}

void loop() {
  // Main loop
  delay(1000);
}
