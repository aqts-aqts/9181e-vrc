#pragma once
#include "main.h"

#define reverseFW 1
#define reverseFW2 -1
#define reverseIntake -1
#define reverseIndexer -1

#define aimTurnSpeed 117 // easier turning as more power can be allocated to turn rather than just lowering
#define flywheelGearRatio 7.5 // ratio between motor power and angular velocity of flywheel

#define indexerFeedSpeed 127
#define intakeFeedSpeed 120
#define minDiscWidth 5

namespace global {
    extern pros::Motor FW;
    extern pros::Motor FW2;
    extern pros::Motor intake;
    extern pros::Motor indexer;

    extern pros::Distance wall;
    extern pros::Optical colour;
    extern pros::Vision vision;
    extern pros::ADIDigitalOut expansion;
    extern pros::ADIEncoder encoder;

    extern void init();
    extern void updateDisplay();

    extern double flyVelocity;
    extern double flyPower;
    extern int elapsed;
    // extern int discs;
}