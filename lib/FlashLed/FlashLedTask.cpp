#include "FlashLedTask.h"
#include "FlashLed.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "FlashLedTask";

Task blinkTask;   // később hozzárendeljük a funkciót

int blinkCount = 0;
int totalBlinks = 0;
int onTime = 200;
int offTime = 200;
bool ledState = false;

// --- Villogtató callback ---
void blinkCallback() {
  ledState = !ledState;
  digitalWrite(FLASHLED_PIN, ledState);

  if (ledState) {
    blinkCount++;
    if (blinkCount >= totalBlinks) {
      blinkTask.disable();
      digitalWrite(FLASHLED_PIN, LOW);
      ESP_LOGI(TAG, "✅ Villogás kész");
      return;
    }
    blinkTask.setInterval(onTime);   // LED be idő
  } else {
    blinkTask.setInterval(offTime);  // LED ki idő
  }
}

// --- Villogás indító függvény ---
void startBlink(int count, int on_ms, int off_ms) {
  totalBlinks = count;
  blinkCount = 0;
  onTime = on_ms;
  offTime = off_ms;
  ledState = false;

  blinkTask.setCallback(&blinkCallback);
  blinkTask.setInterval(onTime);
  blinkTask.setIterations(TASK_FOREVER);
  blinkTask.enable();

  ESP_LOGI(TAG, "💡 Villogás indítva: %d villanás, on=%dms off=%dms",
                count, on_ms, off_ms);
}

void setupFlashLedTask(Scheduler& runner) {
  runner.addTask(blinkTask);
}
