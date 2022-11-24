#include "main.h"
using namespace global;

namespace global {
    void take(int delay, bool stop, int iV=127, int fV=-127) {
        intake.move(iV * reverseIntake);
        feeder.move(fV * reverseFeeder);
        pros::delay(delay);
        if (stop) {
            intake.move(0);
            feeder.move(0);
        }
    }
}