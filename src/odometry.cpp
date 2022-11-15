#include "main.h"
using namespace global;

double lastLeft = 0;
double lastRight = 0;
double lastTracking = 0;

double deltaTheta = 0;
double newTheta = 0;
double thetaM = 0;

double curLeft = 0;
double curRight = 0;
double curTracking = 0;

double leftReset = 0;
double rightReset = 0;
double thetaReset = 0;

double deltaLeft = 0;
double deltaRight = 0;
double deltaTracking = 0;

double deltaLr = 0;
double deltaRr = 0;

double deltaX = 0;
double deltaY = 0;

double theta = 0;
double radius = 0;

double targetX = 0;
double targetY = 0;
double dx = 0;
double dy = 0;

double targetHeight = 0;
double flyVelocity = 0;

namespace global {
    Robot robot; 
    double targetAngle;
    double targetDistance;
    
    void updatePosition() {
        curLeft = encoderLeft.get_value(); // get encoder positions
        curRight = encoderRight.get_value(); 
        curTracking = encoderX.get_value(); 

        deltaLeft = (curLeft - lastLeft) * (M_PI / 180) * (wheelDiameter / 2); // arc angle changes
        deltaRight = (curRight - lastRight) * (M_PI / 180) * (wheelDiameter / 2);
        deltaTracking = (curTracking - lastTracking) * (M_PI / 180) * (trackingDiameter / 2);

        lastLeft = curLeft; // set previous position 
        lastRight = curRight;
        lastTracking = curTracking;

        deltaLr = (curLeft - leftReset) * (M_PI * 180) * (wheelDiameter / 2); // get position changes
        deltaRr = (curRight - rightReset) * (M_PI * 180) * (wheelDiameter / 2);
        
        newTheta = (thetaReset + (deltaLr - deltaRr) / (centerToLeft + centerToRight));
        deltaTheta = newTheta - robot.angle; // get difference of angle
        deltaTracking =  deltaTracking - centerToTracking * deltaTheta; // get difference of tracking wheel

        if (deltaTheta == 0) {
            deltaX = deltaTracking;
            deltaY = deltaRight;
        } else {
            deltaX = (2 * sin(deltaTheta / 2)) * (deltaTracking / deltaTheta + centerToTracking);
            deltaY = (2 * sin(deltaTheta / 2)) * (deltaRight / deltaTheta + centerToRight);
        }

        thetaM = robot.angle + deltaTheta / 2;
        theta = atan2(deltaY, deltaX);
        radius = sqrt(deltaX * deltaX + deltaY * deltaY);
        theta = theta - thetaM;
        deltaX = radius * cos(theta); // get position change from radius
        deltaY = radius * sin(theta);

        newTheta += M_PI;
        while (newTheta <= 0) newTheta += 2 * M_PI; // always positive angle
        newTheta += fmod(newTheta, 2 * M_PI);
        newTheta -= M_PI; // get angle change

        robot.angle = newTheta; // set new values
        robot.x = robot.x - deltaX;
        robot.y = robot.y + deltaY;

        targetX = (robot.team) ? blueGoalX: redGoalX; // get target goal position
        targetY = (robot.team) ? blueGoalY: redGoalY;
        targetHeight = (robot.team) ? blueHeight: redHeight;

        dx = targetX - robot.x; // find difference of positions
        dy = targetY - robot.y;
        targetAngle = atan2(dy, dx) * 180 / M_PI; // get target angle for aiming
        targetDistance = sqrt(pow(dx, 2) + pow(dy, 2)); // get distance to target
        
        flyVelocity = targetDistance / cos(launchAngle); // get linear velocity
        flyVelocity *= sqrt(gravity / (2 * (targetDistance * tan(launchAngle) - (targetHeight - launchHeight))));
        flyVelocity *= (60 / (flyRadius * M_PI)); // convert linear velocity to angular velocity (RPM)
    }
}