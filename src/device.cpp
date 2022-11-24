#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
using namespace global;

namespace global {
    pros::Motor FW(2, pros::E_MOTOR_GEARSET_18);
    pros::Motor FW2(14, pros::E_MOTOR_GEARSET_18);
    pros::Motor intake(11, pros::E_MOTOR_GEARSET_18);
    pros::Motor feeder(7, pros::E_MOTOR_GEARSET_36);

    pros::Distance indexer(0);
    pros::ADIEncoder encoder(0, 0);
    pros::ADIDigitalOut SL(0, 0);
    pros::ADIDigitalOut SR(0, 0);
    
    double flyVelocity;
    double flyPower;
    int elapsed;

    void init() {
        flyPower = 1.0; // Flywheel power percentage
        elapsed = 0; // Time since opcontrol started
        discs = 0; // Number of disks 

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
        encoder.reset();
    }
    
    void updateDisplay() {
        pros::lcd::print(0, "X: %d", robot.x);
        pros::lcd::print(1, "Y: %d", robot.y);
        pros::lcd::print(2, "Angle: %d", robot.angle);
    }
}