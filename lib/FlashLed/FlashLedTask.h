#include <TaskSchedulerDeclarations.h>

extern Task tFlashLed;

void setupFlashLedTask(Scheduler& runner);
void startBlink(int count, int onTime, int offTime);
