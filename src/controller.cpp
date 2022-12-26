#include "main.h"
using namespace global;

double prevError = 0;
double totalError = 0;
double derivative;
double motorPower;

namespace global {
    void aim(bool team, double bound) {
        pros::vision_object_s_t goal;
        while (goal.x_middle_coord < bound) {
            goal = pros::c::vision_get_by_sig(VISION_PORT, 0, (team) ? RED_SIG: BLUE_SIG);
            totalError += goal.x_middle_coord;
            derivative = goal.x_middle_coord - prevError;

            motorPower = goal.x_middle_coord * aimkP + totalError * aimkI + derivative * aimkD;
            for (pros::Motor motor: chassis.left_motors) motor.move(motorPower);
            for (pros::Motor motor: chassis.right_motors) motor.move(-motorPower);
            prevError = goal.x_middle_coord;
            pros::delay(10);
        }
    }

    void roll(bool team, double volts=-127, bool stop=1) {
        pros::c::optical_rgb_s_t rgb = colour.get_rgb();
        bool rolled = (team) ? (rgb.red > rgb.blue): (rgb.blue < rgb.red); // blue = 0, red = 1
        indexer.move(volts * reverseIndexer);
        while (!rolled) pros::delay(10);
        if (stop) indexer.move(0);
    }
}