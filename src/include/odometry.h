#pragma once
#include "main.h"

#define centerToLeft 5.125 // distance from tracking center to middle of left wheels
#define centerToRight 5.125 // distance from tracking center to middle of right wheels
#define centerToTracking 7.75 // distance from tracking center to tracking wheel
#define wheelDiameter 3.25 // diameter of the side wheels
#define trackingDiameter 2.75 // diameter of tracking wheel

#define blueGoalX 0 // x coordinate of blue goal
#define blueGoalY 0 // y coordinate of blue goal
#define redGoalX 0 // x coordinate of red goal
#define redGoalY 0 // y coordinate of red goal

// #define blueHeight 0 // height of blue goal
// #define redHeight 0 // height of red goal
// #define launchAngle 0 // angle of flywheel launch
// #define launchHeight 0 // height of flywheel launch

// #define gravity 9.81 // gravitational constant
// #define flyRadius 0 // radius of flywheel in METERS

namespace global {
    struct Robot {
        double x;
        double y;
        double angle;
        bool team;
    };

    extern Robot robot;
    extern double targetAngle;
    extern double targetDistance;

    extern void updatePosition();
}