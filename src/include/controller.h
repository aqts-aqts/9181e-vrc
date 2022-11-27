#pragma once
#include "main.h"

#define redRollMin 240
#define blueRollMin 240

#define intakeVolts 127
#define feederVolts -127
#define rollerVolts -127

namespace global {
    void take(int delay, bool stop, int iV, int fV);
    void feed(int delay, bool stop, int iV, int fV);
    void roll(bool team, int fV, int maxTime, int delayStep);
}