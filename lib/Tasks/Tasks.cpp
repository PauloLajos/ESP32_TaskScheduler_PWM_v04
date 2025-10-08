#include "Tasks.h"
#include <TaskScheduler.h>
#include "FadeTask.h"
#include "HourlyTask.h"
#include "TimeSyncTask.h"
#include "SensorsTask.h"
#include "ThingSpeakSendTask.h"
#include "esp_log.h"

static const char* TAG = "Tasks";

Scheduler runner;

void setupTasks() {
  runner.init();
  
  setupFadeTask(runner);
  setupHourlyTask(runner);
  setupTimeSyncTask(runner);
  setupSensorsTask(runner);
  setupThingSpeakSendTask(runner);

  ESP_LOGI(TAG, "Tasks initialized");
}

void runTasks() {
  runner.execute();
}
