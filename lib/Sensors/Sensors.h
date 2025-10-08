#pragma once
#include <Arduino.h>

static float lastTemperature = 0.0;
static float lastHumidity = 0.0;

void setupSensors();
void readSensors();
