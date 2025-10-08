#include "LDR_Sensor.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "LDR_Sensor";

void ldr_begin() {
    pinMode(LDR_PIN, INPUT);
}

float ldr_read() {
    //return analogRead(pin);
    return map(analogRead(LDR_PIN), 0, 4095, 0, 100); // százalékos érték 0-100% tartományban
}
