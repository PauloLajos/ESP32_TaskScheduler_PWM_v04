#include <Arduino.h>
#include "WifiManager.h"
#include "TimeSync.h"
#include "LedCtrl.h"
#include "Tasks.h"
#include "Sensors.h"
#include "ThingSpeakSend.h"
#include "esp_log.h"

static const char* TAG = "Main";

void setup() {
  Serial.begin(115200);
  delay(1000);
  ESP_LOGI(TAG, "System start...");

  setupWiFi();
  setupTime();
  setupLeds();
  setupSensors();
  setupThingspeakSend();
  setupTasks();
}

void loop() {
  runTasks();
}
