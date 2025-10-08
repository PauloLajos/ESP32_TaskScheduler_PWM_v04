#include "Sensors.h"
#include "FlashLedTask.h"
#include "DHT_Sensor/DHT_Sensor.h"
#include "LDR_Sensor/LDR_Sensor.h"
#include "DS18B20_Sensor/DS18B20_Sensor.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "Sensors";

float lastTemperature = 0.0;
float lastHumidity = 0.0;
float lastWaterTemp = 0.0;
float lastLDRValue = 0.0;

void setupSensors() {
  // DHT szenzor indítás
  dht_begin(DHT_PIN, DHT_TYPE);
  ESP_LOGI(TAG, "DHT sensor initialized on pin %d, type %d", DHT_PIN, DHT_TYPE);

  // LDR szenzor indítás
  ldr_begin();
  ESP_LOGI(TAG, "LDR sensor initialized on pin %d", LDR_PIN);

  // DS18B20 szenzor indítás
  ds18b20_begin();
  ESP_LOGI(TAG, "DS18B20 sensor initialized on pin %d", DS18B20_PIN);
}

void readSensors() {
  // DHT szenzor olvasása
  float temperature = dht_readTemperature();
  float humidity = dht_readHumidity();
  
  if (!isnan(temperature) || !isnan(humidity)) {
    lastTemperature = temperature;
    lastHumidity = humidity;
    ESP_LOGI(TAG, "DHT Sensor - Temperature: %.2f °C, Humidity: %.2f %%", lastTemperature, lastHumidity);
  } else {
    // Hiba a DHT22 szenzor olvasásakor
    ESP_LOGE(TAG, "Failed to read from DHT sensor!");
  }

  // LDR szenzor olvasása
  float ldrValue = ldr_read();
  if (!isnan(ldrValue)) {
    lastLDRValue = ldrValue;
  } else {
    ESP_LOGE(TAG, "Failed to read from LDR sensor!");
  }
  ESP_LOGI(TAG, "LDR Sensor - Light Level: %.2f %%", ldrValue);

  // DS18B20 szenzor olvasása
  float waterTemp = ds18b20_readTemperature();
  if (!isnan(waterTemp)) {
    lastWaterTemp = waterTemp;
    ESP_LOGI(TAG, "DS18B20 Sensor - Water Temperature: %.2f °C", lastWaterTemp);
  } else {
    ESP_LOGE(TAG, "Failed to read from DS18B20 sensor!");
  }
}

// Visszaadja az utoljára olvasott értékeket
float getLastTemperature() { return lastTemperature; }
float getLastHumidity() { return lastHumidity; }
float getLastLDRValue() { return lastLDRValue; }
float getLastWaterTemp() { return lastWaterTemp; }
