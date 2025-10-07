#include "WifiManager.h"
#include <WiFi.h>
#include "config.h"

static bool wifiConnected = false;

void WiFiEventHandler(WiFiEvent_t event) {
  switch(event) {
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.println("WiFi: Connected to AP");
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      wifiConnected = true;
      Serial.print("WiFi: IP address: ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      wifiConnected = false;
      Serial.println("WiFi: Disconnected");
      WiFi.reconnect();
      break;
    default: break;
  }
}

void setupWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiEventHandler);
  WiFi.begin("YOUR_SSID", "YOUR_PASSWORD");
  Serial.println("WiFi: Connecting...");
}

void loopWiFi() {
  // opcionális reconnect logika
}

bool isWiFiConnected() {
  return wifiConnected;
}
