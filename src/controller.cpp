#include "main.h"
using namespace global;

namespace global {
    void take(int delay, bool stop, int iV=intakeVolts, int fV=feederVolts) {
        intake.move(iV * reverseIntake);
        feeder.move(fV * reverseFeeder);
        pros::delay(delay);
        if (stop) {
            intake.move(0);
            feeder.move(0);
        }
    }

    void feed(int delay, bool stop, int iV=intakeFeedSpeed, int fV=feederFeedSpeed) {
        intake.move(iV * reverseIntake);
        feeder.move(fV * reverseIntake);
        pros::delay(delay);
        if (stop) {
            intake.move(0);
            feeder.move(0);
        }
    }

    void roll(bool team, int fV=rollerVolts, int maxTime=500, int delayStep=10) {
        feeder.move(fV * reverseIntake);
        pros::c::optical_rgb_s_t rgb;
        int timeElapsed = 0;

        while (timeElapsed < maxTime) {
            if (((team) ? rgb.red: rgb.blue) > ((team) ? redRollMin: blueRollMin)) {
                
            }
        }
    }
}