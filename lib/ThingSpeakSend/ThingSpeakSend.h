#pragma once
#include <Arduino.h>

void setupThingspeakSend();
bool thingspeak_send(float temperature, float humidity);
