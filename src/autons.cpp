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
  indexer.move(-127 * reverseIndexer); // roll roller

  FW.move(1 * 127 * reverseFW); // start flywheel
  FW2.move(1 * 127 * reverseFW2);

  chassis.set_drive_pid(-4, DRIVE_SPEED, true); // back into roller
  chassis.wait_drive();

  chassis.set_drive_pid(7, DRIVE_SPEED, true);
  chassis.wait_drive();
  indexer.move(0);

  chassis.set_turn_pid(-12, TURN_SPEED);
  chassis.wait_drive();

  intake.move(127 * reverseIntake);
  pros::delay(3000);
  indexer.move(indexerFeedSpeed * reverseIndexer);
  pros::delay(300);

  indexer.move(-indexerFeedSpeed * reverseIndexer);
  pros::delay(500);
  indexer.move(0);
  pros::delay(400);

  indexer.move(indexerFeedSpeed * reverseIndexer);
  pros::delay(300);
  indexer.move(0);
  pros::delay(200);

  chassis.set_turn_pid(52, TURN_SPEED); // turn to move to middle
  chassis.wait_drive();

  FW.move(0.92 * 127 * reverseFW); // start flywheel
  FW2.move(0.92 * 127 * reverseFW2);

  chassis.set_drive_pid(35, DRIVE_SPEED, true);
  chassis.wait_drive();

  indexer.move(-127 * reverseIndexer);

  chassis.set_drive_pid(15, 40, true); // move to middle
  chassis.wait_drive();

  chassis.set_turn_pid(-38, SWING_SPEED); // face goal
  chassis.wait_drive();

  indexer.move(0);

  chassis.set_drive_pid(7, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(600);
  
  /*// uncomment for only shooting
  FW.move(0.99 * 127 * reverseFW); // start flywheel
  FW2.move(0.99 * 127 * reverseFW2);
  intake.move(127 * reverseIntake);
  pros::delay(4000);*/

  for (int i = 0; i < 2; i++) {
    indexer.move(indexerFeedSpeed * reverseIndexer);
    pros::delay(200);

    indexer.move(-indexerFeedSpeed * reverseIndexer);
    pros::delay(500);
    indexer.move(0);
    pros::delay(400);

    FW.move(0.9 * 127 * reverseFW); // start flywheel
    FW2.move(0.9 * 127 * reverseFW2);
  }
  
  indexer.move(indexerFeedSpeed * reverseIndexer);
  pros::delay(200);
  indexer.move(0);
  pros::delay(300);

  FW.move(0);
  FW2.move(0);

  intake.move(127 * reverseIntake);
  indexer.move(-127 * reverseIndexer);

  chassis.set_drive_pid(-12, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 42.5, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(85, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move(0);
  indexer.move(60 * reverseIndexer);

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-4, DRIVE_SPEED, true); // back into roller
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, true);
  chassis.wait_drive();

  indexer.move(0);
}

void right_side() {
  chassis.set_drive_pid(27, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(18.5, TURN_SPEED);
  chassis.wait_drive();

  FW.move(0.98 * 127 * reverseFW); // start flywheel
  FW2.move(0.98 * 127 * reverseFW2);
  intake.move(127 * reverseIntake);

  pros::delay(2000);

  indexer.move(indexerFeedSpeed * reverseIndexer);
  pros::delay(400);

  indexer.move(-indexerFeedSpeed * reverseIndexer);
  pros::delay(500);
  indexer.move(0);
  pros::delay(400);

  indexer.move(indexerFeedSpeed * reverseIndexer);
  pros::delay(500);

  FW.move(0);
  FW2.move(0);
  indexer.move(60 * reverseIndexer);

  chassis.set_swing_pid(ez::LEFT_SWING, -55, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-28, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, true);
  chassis.wait_drive();
}


void solo_awp() {
  indexer.move(50 * reverseIndexer); // roll roller

  chassis.set_drive_pid(-4, DRIVE_SPEED, true); // back into roller
  chassis.wait_drive();
  indexer.move(0);

  chassis.set_swing_pid(ez::LEFT_SWING, 52, SWING_SPEED); // turn to move to middle
  chassis.wait_drive();

  FW.move(0.95 * 127 * reverseFW); // start flywheel
  FW2.move(0.95 * 127 * reverseFW2);

  chassis.set_drive_pid(36, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move(127 * reverseIntake);
  indexer.move(-127 * reverseIndexer);

  chassis.set_drive_pid(18, 40, true); // move to middle
  chassis.wait_drive();

  chassis.set_turn_pid(-39, SWING_SPEED); // face goal
  chassis.wait_drive();

  indexer.move(0);

  chassis.set_drive_pid(7, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(600);
  
  /*// uncomment for only shooting
  FW.move(0.99 * 127 * reverseFW); // start flywheel
  FW2.move(0.99 * 127 * reverseFW2);
  intake.move(127 * reverseIntake);
  pros::delay(4000);*/

  for (int i = 0; i < 2; i++) {
    indexer.move(indexerFeedSpeed * reverseIndexer);
    pros::delay(400);

    indexer.move(-indexerFeedSpeed * reverseIndexer);
    pros::delay(500);
    indexer.move(0);
    pros::delay(400);
  }
  
  indexer.move(indexerFeedSpeed * reverseIndexer);
  pros::delay(400);
  indexer.move(0);
  pros::delay(200);

  FW.move(0);
  FW2.move(0);

  intake.move(127 * reverseIntake);
  indexer.move(-127 * reverseIndexer);

  chassis.set_drive_pid(-12, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::LEFT_SWING, 41, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(81, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move(0);
  indexer.move(60 * reverseIndexer);

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-4, DRIVE_SPEED, true); // back into roller
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, true);
  chassis.wait_drive();

  indexer.move(0);
}