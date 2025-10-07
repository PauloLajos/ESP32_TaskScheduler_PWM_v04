#include "TimeSync.h"
#include "WifiManager.h"
#include "config.h"
#include <time.h>

void setupTime() {
  configTime(0, 0, NTP_SERVER);
  Serial.println("NTP: waiting for time...");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nNTP: time synced");
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
