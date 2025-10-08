#include "SensorsTask.h"
#include "Sensors.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "SensorsTask";


void sensorsTaskCallback();
Task tSensors(SENSORS_INTERVAL, TASK_FOREVER, &sensorsTaskCallback);

void sensorsTaskCallback() {
  readSensors();
  ESP_LOGI(TAG, "Sensors task executed");
}

void setupSensorsTask(Scheduler& runner) {
  runner.addTask(tSensors);
  tSensors.enable();
}

