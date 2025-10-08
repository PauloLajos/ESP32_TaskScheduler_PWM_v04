#include "TimeSync.h"
#include "WifiManager.h"
#include "config.h"
#include <time.h>
#include "NTPClient.h"
#include "WiFi.h"
#include "esp_log.h"

static const char* TAG = "TimeSync";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_SERVER, 0, 60000); // frissítés 60 másodpercenként

void setupTime() {
  ESP_LOGI(TAG, "NTP szinkronizálás indítása...");
/*  configTzTime(TIMEZONE, NTP_SERVER, NTP_SERVER2);
  ESP_LOGI(TAG, "NTP: waiting for time...");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    delay(500);
    ESP_LOGI(TAG, "waiting for time...");
  }
  ESP_LOGI(TAG, "NTP: time synced");
  */
  if (!isWiFiConnected()) {
    ESP_LOGW(TAG, "WiFi not connected yet, skipping NTP sync.");
    return;
  }

  timeClient.begin();
  if (timeClient.forceUpdate()) {
    unsigned long epochTime = timeClient.getEpochTime();
    struct tm * timeinfo = localtime((time_t *)&epochTime);
    setenv("TZ", TIMEZONE, 1);
    tzset();
    ESP_LOGI(TAG, "NTP: time synced via NTPClient");
  } else {
    ESP_LOGE(TAG, "NTP: failed to sync time via NTPClient");
  }
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    ESP_LOGE(TAG, "Failed to obtain time");
    return;
  }

  char timeStr[40];
  strftime(timeStr, sizeof(timeStr), "%Y.%m.%d. %H:%M:%S", &timeinfo);
  ESP_LOGI(TAG, "Current time: %s", timeStr);
}

void syncTimeDaily() {
/*  static unsigned long lastSync = 0;
  if (millis() - lastSync > 86400000UL) {
    if (isWiFiConnected()) {
      setupTime();
      lastSync = millis();
    }
  }
*/
  if (!isWiFiConnected()) {
    ESP_LOGW(TAG, "WiFi not connected, skipping NTP sync.");
    return;
  }
  if (timeClient.forceUpdate()) {
    ESP_LOGI(TAG, "NTP: time synced via NTPClient");
  } else {
    ESP_LOGE(TAG, "NTP: failed to sync time via NTPClient");
  }
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    ESP_LOGE(TAG, "Failed to obtain time");
    return;
  }
  char timeStr[40];
  strftime(timeStr, sizeof(timeStr), "%Y.%m.%d. %H:%M:%S", &timeinfo);
  ESP_LOGI(TAG, "Current time: %s", timeStr);
}

int getCurrentHour() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return 0;
  return timeinfo.tm_hour;
}
