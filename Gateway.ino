#include <WiFi.h>
#include <esp_now.h>
#include <HTTPClient.h>

// ===== CHANGE THIS =====
const char* WIFI_SSID = "Hotspot";            // CHANGE THIS: your WiFi name
const char* WIFI_PASS = "raghu@4567";        // CHANGE THIS: your WiFi password
const char* WRITE_API_KEY = "0L8B5OX4ZKD9M503";   // CHANGE THIS: Write API Key of your ONE channel
// =======================

typedef struct {
  uint8_t nodeId;   // 1..3
  float temp;
  float hum;
} Packet;

Packet latest[3];
volatile bool fresh[3] = {false, false, false};

// Callback for ESP32 core 2.x (your version 2.0.14)
void onReceive(const uint8_t* mac, const uint8_t* data, int len) {
  if (len != sizeof(Packet)) return;
  Packet p;
  memcpy(&p, data, sizeof(p));
  if (p.nodeId < 1 || p.nodeId > 3) return;
  latest[p.nodeId - 1] = p;
  fresh[p.nodeId - 1] = true;
  Serial.printf("Node %d: %.1fC  %.1f%%\n", p.nodeId, p.temp, p.hum);
}

void sendToThingSpeak() {
  String url = "http://api.thingspeak.com/update?api_key=" + String(WRITE_API_KEY);
  bool any = false;
  for (int i = 0; i < 3; i++) {
    if (fresh[i]) {
      url += "&field" + String(2 * i + 1) + "=" + String(latest[i].temp);
      url += "&field" + String(2 * i + 2) + "=" + String(latest[i].hum);
      fresh[i] = false;
      any = true;
    }
  }
  if (!any) return;

  if (WiFi.status() != WL_CONNECTED) WiFi.reconnect();
  HTTPClient http;
  http.begin(url);
  int code = http.GET();
  Serial.printf("ThingSpeak -> HTTP %d\n", code);
  http.end();
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }

  Serial.println();
  Serial.print("Gateway MAC: ");  Serial.println(WiFi.macAddress());   // NOTE THIS DOWN
  Serial.print("WiFi channel: "); Serial.println(WiFi.channel());      // NOTE THIS DOWN

  if (esp_now_init() != ESP_OK) { Serial.println("ESP-NOW init failed"); return; }
  esp_now_register_recv_cb(onReceive);
}

void loop() {
  sendToThingSpeak();
  delay(20000);   // ThingSpeak free tier needs at least 15 s between updates
}