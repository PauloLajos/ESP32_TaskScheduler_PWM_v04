#pragma once
#include <Arduino.h>

void setupLeds();
void setLedTarget(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
void updateFade();
