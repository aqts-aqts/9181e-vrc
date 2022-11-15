#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
using namespace global;

namespace global {
    pros::Controller minor(pros::E_CONTROLLER_PARTNER);

    pros::Motor FW(14, pros::E_MOTOR_GEARSET_18);
    pros::Motor FW2(16, pros::E_MOTOR_GEARSET_18);
    pros::Motor intake(11, pros::E_MOTOR_GEARSET_18);
    pros::Motor feeder(7, pros::E_MOTOR_GEARSET_36);

    pros::ADIDigitalOut SL(0, 0);
    pros::ADIDigitalOut SR(0, 0);

    pros::ADIEncoder encoderLeft(0, 0);
    pros::ADIEncoder encoderRight(0, 0);
    pros::ADIEncoder encoderX(0, 0);

    double flyVelocity;
    double flyPower;
    int elapsed;

    void init() {
        flyPower = 0.8; // Flywheel power percentage
        elapsed = 0; // Time since opcontrol started

        Robot robot;
        robot.x = 0;
        robot.y = 0;
        robot.angle = 0;
        robot.team = 0; // blue = 0, red = 1

        FW.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        FW2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        feeder.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

        master.clear();
        minor.clear();
        
        encoderLeft.reset();
        encoderRight.reset();
        encoderX.reset();
    }

    void updateDisplay() {
        pros::lcd::print(0, "X: %d", robot.x);
        pros::lcd::print(1, "Y: %d", robot.y);
        pros::lcd::print(2, "Angle: %d", robot.angle);
        pros::lcd::print(3, "Velocity: %d", flyVelocity);
        pros::lcd::print(4, "Power: %d", flyPower);
    }
}