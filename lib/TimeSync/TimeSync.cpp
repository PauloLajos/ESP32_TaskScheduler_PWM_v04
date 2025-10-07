#include "TimeSync.h"
#include "WifiManager.h"
#include "config.h"
#include <time.h>
#include "esp_log.h"

static const char* TAG = "TimeSync";

void setupTime() {
  ESP_LOGI(TAG, "NTP szinkronizálás indítása...");
  configTzTime(TIMEZONE, NTP_SERVER, NTP_SERVER2);
  ESP_LOGI(TAG, "NTP: waiting for time...");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    delay(500);
    ESP_LOGI(TAG, "waiting for time...");
  }
  ESP_LOGI(TAG, "NTP: time synced");
  
  char timeStr[40];
  strftime(timeStr, sizeof(timeStr), "%Y.%m.%d. %H:%M:%S", &timeinfo);
  ESP_LOGI(TAG, "Current time: %s", timeStr);
}

void syncTimeDaily() {
  static unsigned long lastSync = 0;
  if (millis() - lastSync > 86400000UL) {
    if (isWiFiConnected()) {
      setupTime();
      lastSync = millis();
    }
  }
}

int getCurrentHour() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return 0;
  return timeinfo.tm_hour;
}
