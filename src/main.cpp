#include <Arduino.h>
#include "WifiManager.h"
#include "TimeSync.h"
#include "LedCtrl.h"
#include "Tasks.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nSystem start...");

  setupWiFi();
  setupTime();
  setupLeds();
  setupTasks();
}

void loop() {
  loopWiFi();
  runTasks();
}
