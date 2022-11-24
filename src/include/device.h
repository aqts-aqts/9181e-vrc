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
#define minDiscWidth 5

namespace global {
    extern pros::Motor FW;
    extern pros::Motor FW2;
    extern pros::Motor intake;
    extern pros::Motor feeder;

    extern pros::Distance indexer;
    extern pros::ADIDigitalOut SL;
    extern pros::ADIDigitalOut SR;
    extern pros::ADIEncoder encoder;

    extern void init();
    extern void updateDisplay();

    extern double flyVelocity;
    extern double flyPower;
    extern int elapsed;
    extern int discs;
}