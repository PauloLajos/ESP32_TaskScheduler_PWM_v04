#pragma once
#include <Arduino.h>
#include <DHT.h>

void dht_begin(uint8_t pin, uint8_t type);
float dht_readTemperature();
float dht_readHumidity();
