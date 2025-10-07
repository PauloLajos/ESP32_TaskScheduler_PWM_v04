#include "FadeTask.h"
#include "LedCtrl.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "FadeTask";

void fadeTaskCallback();
Task tFade(FADE_INTERVAL, TASK_FOREVER, &fadeTaskCallback);

void setupFadeTask() {
  // A tFade task már létre van hozva fent, csak engedélyezni kell
  tFade.enable();
}

void fadeTaskCallback() {
  updateFade();
  ESP_LOGI(TAG, "Fade task executed");
}
