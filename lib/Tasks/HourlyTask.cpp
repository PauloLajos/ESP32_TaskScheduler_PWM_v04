#include "HourlyTask.h"
#include "LedCtrl.h"
#include "config.h"

Task hourlyTask(3600000, TASK_FOREVER, &hourlyUpdate); // 1 óra

void setupHourlyTask() {
  hourlyTask.setInterval(3600000); // frissítés óránként
}

void hourlyUpdate() {
  time_t now = time(nullptr);
  struct tm *t = localtime(&now);
  int hour = t->tm_hour;

  float r = hourly_brightness[hour][0] / 255.0f;
  float g = hourly_brightness[hour][1] / 255.0f;
  float b = hourly_brightness[hour][2] / 255.0f;
  float w = hourly_brightness[hour][3] / 255.0f;

  setLedTargets(r, g, b, w); // PWM modulban implementálva
}
