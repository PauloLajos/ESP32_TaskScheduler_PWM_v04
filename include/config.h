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

// Szenzorok olvasási gyakorisága
#define SENSORS_INTERVAL 5*60*1000UL  // 5 perc
