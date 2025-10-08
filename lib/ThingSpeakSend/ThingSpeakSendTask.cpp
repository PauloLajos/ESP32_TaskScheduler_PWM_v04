#include "ThingSpeakSendTask.h"
#include "ThingSpeakSend.h"
#include "Sensors.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "ThingSpeakTask";

void thingSpeakSendTaskCallback();
Task tThingSpeakSend(THINGSPEAK_INTERVAL, TASK_FOREVER, &thingSpeakSendTaskCallback);

void thingSpeakSendTaskCallback() {
  bool success = thingspeak_send(lastTemperature, lastHumidity);
  if (success) {
    ESP_LOGI(TAG, "ThingSpeak task executed successfully");
  } else {
    ESP_LOGW(TAG, "ThingSpeak task execution failed");
  }
}

void setupThingSpeakSendTask(Scheduler& runner) {
  runner.addTask(tThingSpeakSend);
  tThingSpeakSend.enable();
}
