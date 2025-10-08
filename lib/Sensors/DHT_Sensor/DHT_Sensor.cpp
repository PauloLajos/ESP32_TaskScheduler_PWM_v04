#include "DHT_Sensor.h"

static DHT dht(0, 0);   // globális, inicializálás nélkül

void dht_begin(uint8_t pin, uint8_t type) {
    dht = DHT(pin, type);
    dht.begin();
}

float dht_readTemperature() {
    return dht.readTemperature();
}

float dht_readHumidity() {
    return dht.readHumidity();
}
