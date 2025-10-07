#include "Tasks.h"
#include "FadeTask.h"
#include "HourlyTask.h"

Scheduler runner;

// a két task deklarálása
extern Task fadeTask;
extern Task hourlyTask;

void setupTasks() {
  setupFadeTask();
  setupHourlyTask();

  runner.init();
  runner.addTask(fadeTask);
  runner.addTask(hourlyTask);

  fadeTask.enable();
  hourlyTask.enable();
}

void runTasks() {
  runner.execute();
}
