#pragma once
#include "main.h"

#define intakeVolts 127
#define indexerVolts -127
#define rollerVolts -127

#define VISION_PORT 0
#define BLUE_SIG 0
#define RED_SIG 0

#define aimkP 0
#define aimkI 0
#define aimkD 0

namespace global {
    void aim(bool team, double bound);
    void roll(bool team, double volts, bool stop);
}