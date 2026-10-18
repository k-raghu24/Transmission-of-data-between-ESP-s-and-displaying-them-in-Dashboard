#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <DHT.h>

// ===== CHANGE THIS =====
#define NODE_ID      3    // CHANGE THIS: 1, 2 or 3 (change before each upload)
#define WIFI_CHANNEL 6     // CHANGE THIS: WiFi channel printed by the gateway

// CHANGE THIS: gateway MAC printed by the gateway.
// Example: A4:CF:12:9B:34:5E  becomes  {0xA4, 0xCF, 0x12, 0x9B, 0x34, 0x5E}
uint8_t gatewayMAC[] = {0x1C, 0xC3, 0xAB, 0xB2, 0xE9, 0x18};

#define DHTPIN   4         // DHT22 data pin
#define DHTTYPE  DHT22
// =======================

typedef struct {
  uint8_t nodeId;
  float temp;
  float hum;
} Packet;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.mode(WIFI_STA);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_channel(WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);
  esp_wifi_set_promiscuous(false);

  if (esp_now_init() != ESP_OK) { Serial.println("ESP-NOW init failed"); return; }

  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, gatewayMAC, 6);
  peer.channel = WIFI_CHANNEL;
  peer.encrypt = false;
  esp_now_add_peer(&peer);
}

void loop() {
  Packet p;
  p.nodeId = NODE_ID;
  p.temp = dht.readTemperature();
  p.hum  = dht.readHumidity();

  if (isnan(p.temp) || isnan(p.hum)) {
    Serial.println("DHT read failed, check wiring");
  } else {
    esp_err_t r = esp_now_send(gatewayMAC, (uint8_t*)&p, sizeof(p));
    Serial.printf("Sent: %.1fC  %.1f%%  (%s)\n", p.temp, p.hum, r == ESP_OK ? "ok" : "error");
  }
  delay(3000);   // send every 30 s
}