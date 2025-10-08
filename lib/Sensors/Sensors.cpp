#include "Sensors.h"
#include "DHTSensor/DHTSensor.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "Sensors";

void setupSensors() {
  // DHT szenzor indítás
  dht_begin(DHT_PIN, DHT_TYPE);
  ESP_LOGI(TAG, "DHT sensor initialized on pin %d, type %d", DHT_PIN, DHT_TYPE);
}

void readSensors() {
  // DHT szenzor olvasása
  float temperature = dht_readTemperature();
  float humidity = dht_readHumidity();
  ESP_LOGI(TAG, "DHT Sensor - Temperature: %.2f °C, Humidity: %.2f %%", temperature, humidity);
  if (!isnan(temperature) || !isnan(humidity)) {
    lastTemperature = temperature;
    lastHumidity = humidity;
  } else {
    // Hiba a DHT22 szenzor olvasásakor
    ESP_LOGE(TAG, "Failed to read from DHT sensor!");
  }
}
