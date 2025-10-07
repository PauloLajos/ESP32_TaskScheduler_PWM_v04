#include "LedCtrl.h"
#include "config.h"
#include <math.h>

static float current[CHANNELS] = {0};
static float target[CHANNELS] = {0};

static uint8_t pins[CHANNELS] = {PIN_R, PIN_G, PIN_B, PIN_W};

void setupLeds() {
  for (int i = 0; i < CHANNELS; i++) {
    ledcSetup(i, LEDC_BASE_FREQ, LEDC_TIMER_BITS);
    ledcAttachPin(pins[i], i);
    ledcWrite(i, 0);
  }
}

void setLedTarget(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  target[0] = r;
  target[1] = g;
  target[2] = b;
  target[3] = w;
}

static uint8_t gammaCorrect(float val) {
  return powf(val / 255.0, GAMMA) * 255.0;
}

void updateFade() {
  for (int i = 0; i < CHANNELS; i++) {
    if (fabs(target[i] - current[i]) > 0.1) {
      current[i] += (target[i] - current[i]) / (FADE_MINUTES * 4); // kb. 15 perc alatt
      ledcWrite(i, gammaCorrect(current[i]));
    }
  }
}
