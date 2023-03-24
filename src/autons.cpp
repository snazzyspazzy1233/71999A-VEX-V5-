#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 120; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 100;
const int SWING_SPEED = 100;



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

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
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

/* bool patil = true;
double target;
void flywheelPID(void* param) {
  // Constants
  pros::Motor flywheel(4, pros::E_MOTOR_GEARSET_18);
  double kP = 0.3;
  double kV = 1; 
  double error = 0;
  double prevError = 0;
  double output = 0;
  while (patil) {
    error = target - flywheel.get_actual_velocity();
    output = (kV * target) + (kP * error) ;


    if(output > 127){
      output = 127;
    }
    else if(output < 0){
      output = 0; 
    }
    flywheel = output;
    prevError = error;
    pros::delay(20);
  }


} 
double num;
void set_flywheel(double num) {
  patil = true;
 target = num;
}

*/

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {



pros::Motor Intwake(1, pros::E_MOTOR_GEARSET_18);

//pros::Task PID(flywheelPID);

pros::Motor Flywhel(2, pros::E_MOTOR_GEARSET_18);

Intwake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


pros::ADIDigitalOut angler(1);

  angler.set_value(true);

  //set_flywheel(125);

  Flywhel = 102;

  Intwake = -127;

  chassis.set_drive_pid(20, DRIVE_SPEED,true);

  chassis.wait_drive();

  chassis.set_turn_pid(55, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(4.5, DRIVE_SPEED,true);

  chassis.wait_drive();

  pros::delay(1200);

  Intwake = 127;

  pros::delay(300);

  Intwake = 0;

  Flywhel = 105;

  pros::delay(800);

   Intwake = 127;

  pros::delay(250);

  Intwake = 0;

  pros::delay(300);

   Intwake = 127;

  pros::delay(250);

  Intwake = 0;

  pros::delay(300);

   Intwake = 127;

   pros::delay(300);

  Intwake = 0;

  pros::delay(300);

   Intwake = 127;

  pros::delay(500);

  Intwake = -127;

  Flywhel = 105;

  chassis.set_turn_pid(150, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(15, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(35, TURN_SPEED);

  chassis.wait_drive();

  pros::delay(900);

  Intwake = 127;

  pros::delay(600);

  Intwake = 0;

  chassis.set_turn_pid(-30, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(-10, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 10, SWING_SPEED);

  pros::delay(50);

  Intwake.move_relative(-300, 100);

  angler.set_value(false);

  











  



  


  

  




  /*chassis.set_drive_pid(10, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(35, TURN_SPEED);

  pros::delay(2000);

  Intwake = 127;

  pros::delay(400);

  Intwake = 0;

  pros::delay(300);

  Intwake = 127;

  pros::delay(400);

  Intwake = 0;

  pros:: delay(200);

  Intwake = 127;

  pros:: delay(600);

  Intwake = 0;

  Intwake = -127;

  chassis.wait_drive();
  
  chassis.set_drive_pid(5, DRIVE_SPEED, true);

  chassis.wait_drive();
  
  chassis.set_drive_pid(-6, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(315, TURN_SPEED);

  chassis.wait_drive();
  
  chassis.set_drive_pid(20, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);

  pros::delay(1650);

  Intwake = 127;

  pros::delay(200);

  Intwake = 0;

  pros::delay(280);

  Intwake = 127;

  pros::delay(250);

  Intwake = 0;

  pros:: delay(200);

  Intwake = 127;

  pros:: delay(400);

  chassis.wait_drive();

  chassis.set_turn_pid(315, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true);

  chassis.wait_drive();


*/
  












  /* chassis.set_drive_pid(-2.5, DRIVE_SPEED, true);

  chassis.wait_drive();

  
  

  pros::delay(50);

  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(12, DRIVE_SPEED, true);

  chassis.wait_drive();

  Intwake = -127;

  chassis.set_drive_pid(3, DRIVE_SPEED, true);

  chassis.wait_drive();

  pros::delay(100);

  chassis.set_drive_pid(7, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-30, TURN_SPEED);

    pros::delay(1650);

  Intwake = 127;

  pros::delay(200);

  Intwake = 0;

  pros::delay(250);

  Intwake = 127;

  pros::delay(200);

  Intwake = 0;

  pros:: delay(200);

  Intwake = 127;

  pros:: delay(400);

  Intwake = 0;

  Intwake = -127;

  chassis.set_turn_pid(45, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(30, DRIVE_SPEED, true);

*/








  /* Intwake = -127;

  chassis.set_drive_pid(2, DRIVE_SPEED, true);

  chassis.wait_drive();

  Intwake = 0;

  Intwake = -127;

  chassis.set_turn_pid(-25, TURN_SPEED);

  pros::delay(1650);

  Intwake = 127;

  pros::delay(200);

  Intwake = 0;

  pros::delay(250);

  Intwake = 127;

  pros::delay(200);

  Intwake = 0;

  pros:: delay(200);

  Intwake = 127;

  pros:: delay(400);

  Intwake = 0;

  Intwake = -127;

  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(-44, TURN_SPEED);

  pros::delay(1450);

  Intwake = 127;

  pros::delay(200);

  Intwake = 0;

  pros::delay(250);

  Intwake = 127;

  pros::delay(250);

  Intwake = 0;

  pros:: delay(250);

  Intwake = 127;

  pros:: delay(400);

  Intwake = 0;

  Intwake = -127;

  chassis.set_turn_pid(45, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, true);

  chassis.wait_drive();

  chassis.set_turn_pid(225, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 270, SWING_SPEED);

  Intwake = 0;

  chassis.wait_drive();

  Intwake.move_relative(-300, 100);

*/


}

 /* chassis.set_drive_pid(-2, DRIVE_SPEED, true);
  // wait for brain
  chassis.wait_drive();
  // turn for 90 degrees
  chassis.set_turn_pid(90, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  // wait for brain
  chassis.wait_drive();
  // turn for 90 degrees
  chassis.set_turn_pid(180, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  // wait for brain
  chassis.wait_drive();
  // turn for 90 degrees
  chassis.set_turn_pid(270, TURN_SPEED);

  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  // wait for brain
  chassis.wait_drive();

  //chassis.set_turn_pid(235, TURN_SPEED);

  //chassis.wait_drive();

  //chassis.set_drive_pid(-20,DRIVE_SPEED, true);

  //chassis.set_swing_pid(ez::RIGHT_SWING, 270, SWING_SPEED);
  

 



 //Flywheel = 67


  // flip flywheel angler (up is 1 and down is 0)
  //flywheel_angler(1);
  // spin the flywheel
 // set_flywheel(67);
  // spin the intake
  //Intake = 127; 
// Flywheel = -67 to spin it in reverse
// Intake = -127 to shoot
// To run in degrees, motor.move_relative(Position, Velocity); // Moves 100 degrees forward
// To run intake, intake.move_relative(100, 100); //Turns the intake 100 degrees forward
// For regular flywheel code: Flywheel = 67;

}
*/


///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {

// Flywheeeeeel PID
 // pros::Task flywheel(flywheelPID);
 // drive reverse for 2 inches 
  chassis.set_drive_pid(-2, DRIVE_SPEED, true);
  // wait for brain
  chassis.wait_drive();
  // turn for 90 degrees
  chassis.set_turn_pid(90, TURN_SPEED);
  // flip flywheel angler (up is 1 and down is 0)
  //flywheel_angler(1);
  // spin the flywheel
 // set_flywheel(67);
  // spin the intake
  //Intake = 127; 
// Flywheel = -67 to spin it in reverse
// Intake = -127 to shoot
// To run in degrees, motor.move_relative(Position, Velocity); // Moves 100 degrees forward
// To run intake, intake.move_relative(100, 100); //Turns the intake 100 degrees forward
// For regular flywheel code: Flywheel = 67;

}

// . . .
// Make your own autonomous functions here!
// . . .


