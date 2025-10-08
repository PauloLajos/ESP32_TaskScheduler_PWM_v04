#pragma once
#include <Arduino.h>

// PWM kimenetek
#define PIN_R 19
#define PIN_G 21
#define PIN_B 22
#define PIN_W 23

// LED csatornák száma
#define CHANNELS 4

// PWM beállítás
#define LEDC_TIMER_BITS 10
#define LEDC_BASE_FREQ 5000
#define PWM_RESOLUTION 10  // 10 bit (0-1023)

// NTP szerver
#define NTP_SERVER "pool.ntp.org"
#define NTP_SERVER2 "time.nist.gov"
// Időzóna beállítás (CET/CEST) Budapest
#define TIMEZONE "CET-1CEST,M3.5.0/2,M10.5.0/3"
// Időszinkronizálás gyakorisága
#define TIMESYNC_INTERVAL 24*60*60*1000UL  // 24 óra

// Fade idő percben
#define FADE_MINUTES 60
#define FADE_INTERVAL 1*1000
#define HOURLY_INTERVAL 60*1000

// Gamma korrekció
#define GAMMA 2.2

// 24 órás fényerő táblázat (0..255 között) 
// - az updateFade() hívásban átszámolódik a PWM_RESOLUTION értékre
// Napfelkelte: 6:00–7:00
// Nappal: 7:00–20:00
// Naplemente: 19:00–20:00
const uint8_t hourly_brightness[24][CHANNELS] = {
  //   R,   G,   B,   W
  {  0,   0,   0,   0 },    // 0 óra
  {  0,   0,   0,   0 },    // 1 óra
  {  0,   0,   0,   0 },    // 2 óra
  {  0,   0,   0,   0 },    // 3 óra
  {  0,   0,   0,   0 },    // 4 óra
  {  0,   0,   0,   0 },    // 5 óra
  { 30,  10,   5,  20 },    // 6 óra – napfelkelte kezdete (meleg árnyalat)
  {120,  80,  40, 120 },    // 7 óra – teljes fény
  {200, 160, 120, 200 },    // 8 óra
  {240, 210, 180, 240 },    // 9 óra
  {255, 230, 200, 255 },    //10 óra
  {255, 240, 220, 255 },    //11 óra
  {255, 255, 255, 255 },    //12 óra – csúcserő
  {255, 255, 240, 255 },    //13 óra
  {240, 240, 220, 250 },    //14 óra
  {220, 220, 200, 240 },    //15 óra
  {200, 200, 180, 220 },    //16 óra
  {180, 160, 140, 200 },    //17 óra
  {140, 120, 100, 160 },    //18 óra
  {80,   60,  40, 100 },    //19 óra – naplemente kezdete
  {30,   10,   5,  30 },    //20 óra – naplemente vége
  {10,    5,   2,  10 },    //21 óra
  { 5,    2,   1,   5 },    //22 óra
  { 0,    0,   0,   0 },    //23 óra
};

// ThingSpeak küldési gyakoriság (15 másodperc a minimum)
#define THINGSPEAK_INTERVAL 1*60*1000UL  // 1*60*1000UL = 1 perc

// Szenzorok olvasási gyakorisága
#define SENSORS_INTERVAL 1*60*1000UL  // 1*60*1000UL = 1 perc

// DHT szenzor beállítások
#define DHT_PIN 4          // DHT adat lába
#define DHT_TYPE DHT22     // DHT11, DHT22, DHT21, AM2301
#define DHT_INTERVAL 1*60*1000UL  // 1*60*1000UL = 1 perc

//LDR szenzor beállítások
#define LDR_PIN 34        // LDR analóg lába
#define LDR_INTERVAL 1*60*1000UL  // 1 perc
#define LDR_THRESHOLD 2000  // Küszöbérték a fényerő csökkentéséhez (0-4095 között)
#define LDR_DIM_FACTOR 0.5  // Fényerő csökkentési tényező (0.0 - 1.0 között)
#define LDR_BRIGHT_FACTOR 1.0  // Fényerő növelési tényező (1.0 - 2.0 között)
#define LDR_HYSTERESIS 100  // hiszterézis érték a fényerő változtatásához

// DS18B20 szenzor beállítások
#define DS18B20_PIN 17      // DS18B20 adat lába
#define DS18B20_INTERVAL 1*60*1000UL  // 1 perc
#define DS18B20_RESOLUTION 12  // 9, 10, 11, vagy 12 bit
#define DS18B20_PRECISION 0.1f  // A hőmérséklet olvasás pontossága (pl. 0.1f a 0.1°C pontosságért)
#define DS18B20_MAX_RETRIES 3  // Maximális újrapróbálkozások száma olvasási hiba esetén
#define DS18B20_RETRY_DELAY 200  // Várakozási idő újrapróbálkozás előtt (ms)
#define DS18B20_CONVERSION_TIMEOUT 750  // Maximális idő a hőmérséklet konverzióra (ms)
#define DS18B20_INVALID_TEMP -127.0f  // Érvénytelen hőmérséklet jelző érték
#define DS18B20_MIN_TEMP -55.0f  // Minimális mérhető hőmérséklet
#define DS18B20_MAX_TEMP 125.0f  // Maximális mérhető hőmérséklet
#define DS18B20_ERROR_TEMP -1000.0f  // Hibát jelző hőmérséklet érték
#define DS18B20_READ_INTERVAL 2000  // Várakozási idő két olvasás között (ms)
#define DS18B20_SKIP_INVALID_READINGS true  // Érvénytelen olvasások kihagyása

// Flash LED beállítások
#define FLASHLED_INTERVAL 500   // Flash LED felvillanás időköze (ms)
#define FLASHLED_DURATION 100   // Flash LED felvillanás hossza (ms)
#define FLASHLED_PIN 5          // Flash LED lába 
