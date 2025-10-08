#include <OneWire.h>
#include <DallasTemperature.h>
#include "DS18B20_Sensor.h"
#include "config.h"
#include "esp_log.h"

static const char* TAG = "DS18B20_Sensor";

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);
DeviceAddress tempDeviceAddress;

void ds18b20_begin() {
    sensors.begin();
    if (!sensors.getAddress(tempDeviceAddress, 0)) {
        ESP_LOGE(TAG, "No DS18B20 sensor found!");
    } else {
        ESP_LOGI(TAG, "DS18B20 sensor initialized on pin %d", DS18B20_PIN);
    }
}

float ds18b20_readTemperature() {
    sensors.requestTemperatures();
    return sensors.getTempC(tempDeviceAddress);
}
