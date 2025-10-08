#include "ThingSpeakSendTask.h"
#include "ThingSpeakSend.h"
#include "FlashLedTask.h"
#include "Sensors.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "ThingSpeakTask";

void thingSpeakSendTaskCallback();
Task tThingSpeakSend(THINGSPEAK_INTERVAL, TASK_FOREVER, &thingSpeakSendTaskCallback);

void thingSpeakSendTaskCallback() {
  float temperature = getLastTemperature();
  float humidity = getLastHumidity();
  float waterTemp = getLastWaterTemp();
  float ldrValue = getLastLDRValue();
  // A fényerősség jelenleg nincs használva, így 0.0 értéket küldünk
  float brightness = 0.0;

  bool success = thingspeak_send(temperature, humidity, waterTemp, ldrValue, brightness);
  
  if (success) {
    ESP_LOGI(TAG, "ThingSpeak task executed successfully");
    //
    //
    //

    startBlink(3, 200, 200);


  } else {
    ESP_LOGW(TAG, "ThingSpeak task execution failed");
  }
}

void setupThingSpeakSendTask(Scheduler& runner) {
  runner.addTask(tThingSpeakSend);
  tThingSpeakSend.enable();
}
