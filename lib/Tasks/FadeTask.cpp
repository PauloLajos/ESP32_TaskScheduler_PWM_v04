#include "FadeTask.h"
#include "LedCtrl.h"

Task fadeTask(100, TASK_FOREVER, &fadeStep);

static int fadeValue = 0;
static bool fadeUp = true;

void setupFadeTask() {
  fadeTask.setInterval(100); // pl. 100 ms
}

void fadeStep() {
  if (fadeUp) fadeValue++;
  else fadeValue--;

  if (fadeValue >= 255) fadeUp = false;
  if (fadeValue <= 0) fadeUp = true;

  setLedBrightness(fadeValue / 255.0f);
}
