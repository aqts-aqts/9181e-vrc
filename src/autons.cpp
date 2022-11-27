#include "main.h"
using namespace global;

const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void left_side() {
  chassis.set_drive_pid(-5, DRIVE_SPEED, true); // back into roller
  chassis.wait_drive();

  feeder.move(-127); // roll roller
  pros::delay(500);

  chassis.set_drive_pid(12, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED); // turn to move to middle
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true); // move to middle
  chassis.wait_drive();

  chassis.set_turn_pid(315, TURN_SPEED); // face goal
  chassis.wait_drive();

  FW.move(127); // start flywheel
  FW2.move(127);

  intake.move(intakeFeedSpeed * reverseIntake); // feed
  feeder.move(feederFeedSpeed * reverseFeeder);
  pros::delay(3000);

  FW.move(0);
  FW2.move(0);
  intake.move(0);
  feeder.move(0);
}

void right_side() {}
void solo_awp() {}