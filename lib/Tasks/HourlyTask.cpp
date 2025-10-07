#include "HourlyTask.h"
#include "config.h"
#include "LedCtrl.h"
#include "TimeSync.h"
#include "esp_log.h"

static const char* TAG = "HourlyTask";

static int lastHour = -1;

void hourlyBrightnessTaskCallback();
Task tHourly(HOURLY_INTERVAL, TASK_FOREVER, &hourlyBrightnessTaskCallback);

void setupHourlyTask() {
  // A tHourly task már létre van hozva fent, csak engedélyezni kell
  tHourly.enable();
}

void hourlyBrightnessTaskCallback() {
  int hour = getCurrentHour();
  if (hour != lastHour) {
    setLedTarget(
      hourly_brightness[hour][0],
      hourly_brightness[hour][1],
      hourly_brightness[hour][2],
      hourly_brightness[hour][3]
    );
    lastHour = hour;
  }
  ESP_LOGI(TAG, "Hourly brightness task executed for hour %d", hour);
}
