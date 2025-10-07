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

// NTP szerver
#define NTP_SERVER "pool.ntp.org"

// Fade idő percben
#define FADE_MINUTES 15

// Gamma korrekció
#define GAMMA 2.2

// 24 órás fényerő táblázat (0..255 között)
const uint8_t hourly_brightness[24][CHANNELS] = {
  //   R,   G,   B,   W
  {  0,   0,   0,   0 },
  {  0,   0,   0,   0 },
  {  5,   2,   2,   5 },
  { 20,  10,  10,  20 },
  { 60,  30,  20,  60 },
  {120,  70,  40, 120 },
  {200, 150, 100, 200 },
  {255, 200, 160, 255 },
  {255, 220, 180, 255 },
  {255, 255, 255, 255 },
  {240, 240, 230, 255 },
  {200, 200, 190, 240 },
  {180, 180, 170, 220 },
  {150, 150, 140, 200 },
  {120, 100,  80, 160 },
  {80,   70,  60, 120 },
  {40,   40,  30,  80 },
  {20,   20,  10,  40 },
  {10,   10,   5,  20 },
  { 5,    5,   2,  10 },
  { 0,    0,   0,   0 },
  { 0,    0,   0,   0 },
  { 0,    0,   0,   0 },
  { 0,    0,   0,   0 }
};
