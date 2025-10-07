#pragma once
#include <Arduino.h>
#include <TaskScheduler.h>

extern Scheduler runner;

void setupTasks();
void runTasks();
