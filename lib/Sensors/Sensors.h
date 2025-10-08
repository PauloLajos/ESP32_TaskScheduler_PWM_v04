#pragma once
#include <Arduino.h>

void setupSensors();
void readSensors();
float getLastTemperature();
float getLastHumidity();
