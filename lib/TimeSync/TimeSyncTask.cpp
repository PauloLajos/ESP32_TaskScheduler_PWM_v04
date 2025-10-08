#include "TimeSyncTask.h"
#include "TimeSync.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "TimeSyncTask";

// Napi egyszer lefutó időszinkronizáló task
void timeSyncTaskCallback();
Task tTimeSync(TIMESYNC_INTERVAL, TASK_FOREVER, &timeSyncTaskCallback); // 24 óránként

void setupTimeSyncTask(Scheduler& runner) {
  runner.addTask(tTimeSync);
  tTimeSync.enable();
}

void timeSyncTaskCallback() {
  syncTimeDaily();
  ESP_LOGI(TAG, "Time sync task executed");
}
