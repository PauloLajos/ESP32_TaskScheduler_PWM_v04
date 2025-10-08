#include "FlashLedTask.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "FlashLedTask";

//bool ledState = false;

void setupFlashLed() {
  pinMode(FLASHLED_PIN, OUTPUT);
  digitalWrite(FLASHLED_PIN, LOW); // Kezdetben LED kikapcsolva
  ESP_LOGI(TAG, "Flash LED initialized on pin %d", FLASHLED_PIN);
}
