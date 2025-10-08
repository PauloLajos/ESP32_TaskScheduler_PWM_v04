#include <WiFi.h>
#include <ThingSpeak.h>
#include "config.h"
#include "secrets.h"
#include "ThingSpeakSend.h"
#include "esp_log.h"

WiFiClient client;

static const char* TAG = "ThingSpeak";

// Inicializálás
void setupThingspeakSend() {
  ESP_LOGI(TAG, "Initializing ThingSpeak...");
  ThingSpeak.begin(client);
  ESP_LOGI(TAG, "ThingSpeak ready.");
}

// Adatok küldése ThingSpeak-re
bool thingspeak_send(float temperature, float humidity, float waterTemp, float ldrValue, float brightness) {
  if (WiFi.status() != WL_CONNECTED) {
    ESP_LOGW(TAG, "Skipping update: no WiFi connection");
    return false;
  }

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, waterTemp);
  ThingSpeak.setField(4, ldrValue);
  ThingSpeak.setField(5, brightness);

  ESP_LOGI(TAG, "Sending data → Temp: %.2f °C, Humidity: %.2f %%, Water: %.2f °C, Lumen: %.0f%%, Brightness: %.0f%%", 
    temperature, humidity, waterTemp, ldrValue, brightness);

  int code = ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID, THINGSPEAK_API_KEY);

  if (code == 200) {
    ESP_LOGI(TAG, "ThingSpeak update successful ✅");
    return true;
  } else {
    ESP_LOGE(TAG, "ThingSpeak update failed, code: %d", code);
    return false;
  }
}
