#include "Tasks.h"
#include <TaskScheduler.h>
#include "FadeTask.h"
#include "HourlyTask.h"
#include "TimeSyncTask.h"
#include "esp_log.h"

static const char* TAG = "Tasks";

Scheduler runner;

void setupTasks() {
  runner.init();
  runner.addTask(tFade);
  runner.addTask(tHourly);
  runner.addTask(tTimeSync);
  setupFadeTask();
  setupHourlyTask();
  setupTimeSyncTask();
}

void runTasks() {
  runner.execute();
}
