#include "WifiManager.h"
#include <WiFi.h>
#include "config.h"
#include "secrets.h"
#include "esp_log.h"

static const char* TAG = "WifiManager";

static bool wifiConnected = false;

void WiFiEventHandler(WiFiEvent_t event) {
  switch(event) {
    case SYSTEM_EVENT_STA_CONNECTED:
      ESP_LOGI(TAG, "WiFi: Connected to AP");
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      wifiConnected = true;
      ESP_LOGI(TAG, "WiFi: IP address: %s", WiFi.localIP().toString().c_str());
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      wifiConnected = false;
      ESP_LOGW(TAG, "WiFi: Disconnected");
      WiFi.reconnect();
      break;
    default: break;
  }
}

void setupWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiEventHandler);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  ESP_LOGI(TAG, "WiFi: Connecting...");
}

bool isWiFiConnected() {
  return wifiConnected;
}
