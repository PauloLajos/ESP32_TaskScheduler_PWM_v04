#include "FadeTask.h"
#include "LedCtrl.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "FadeTask";

void fadeTaskCallback();
Task tFade(FADE_INTERVAL, TASK_FOREVER, &fadeTaskCallback);

void setupFadeTask(Scheduler& runner) {
  runner.addTask(tFade);
  tFade.enable();
}

void fadeTaskCallback() {
  updateFade();
  ESP_LOGI(TAG, "Fade task executed");
}
