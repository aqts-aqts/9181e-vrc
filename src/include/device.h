#pragma once
#include "main.h"   

#define reverseFW 1
#define reverseFW2 -1
#define reverseIntake -1
#define reverseFeeder -1

#define aimTurnSpeed 117 // easier turning as more power can be allocated to turn rather than just lowering
#define flywheelGearRatio 7.5 // ratio between motor power and angular velocity of flywheel

#define feederFeedSpeed 30
#define intakeFeedSpeed 85

namespace global {
    extern pros::Controller minor;

    extern pros::Motor FW;
    extern pros::Motor FW2;
    extern pros::Motor intake;
    extern pros::Motor feeder;

    extern pros::ADIDigitalOut SL;
    extern pros::ADIDigitalOut SR;

    extern pros::ADIEncoder encoderX;

    extern void init();
    extern void updateDisplay();

    extern double flyVelocity;
    extern double flyPower;
    extern int elapsed;
}