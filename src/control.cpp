#include "vex.h"
#include "setup.h"


// User control code here, inside the loop
void usercontrol() {

  leftWheels.setStopping(brakeType::coast);
  rightWheels.setStopping(brakeType::coast);
  liftMotors.setStopping(brakeType::hold);
  intakeMotor.setStopping(brakeType::hold);
  while (1) {

    //Get speed from controller joysticks
    int forwardSpeed = Controller1.Axis3.position();   //left joystick output (forward/backward)
    int sideSpeed = Controller1.Axis1.position();    //right joystick output (left/right)

    //Control lift motors with controller buttons
    if (Controller1.ButtonR2.pressing()) {
      liftMotors.spin(forward, 100, percent);
    }
    else if (Controller1.ButtonL2.pressing()) {
      liftMotors.spin(reverse, 100, percent);
    }
    else {
      liftMotors.stop();
    }

    //Control intake motor with controller buttons
    if (Controller1.ButtonB.pressing()) {
      intakeMotors.spin(forward, 100, percent);
    }
    else if (Controller1.ButtonA.pressing()) {
      intakeMotors.spin(reverse, 100, percent);
    }
    else {
      intakeMotors.stop();
    }

    //Control banshee motor with controller buttons
    if (Controller1.ButtonL1.pressing()) {
      bansheeMotor.spin(forward, 100, percent);
    }
    else if (Controller1.ButtonR1.pressing()) {
      bansheeMotor.spin(reverse, 100, percent);
    }
    else {
      bansheeMotor.stop();
    }

    leftWheels.spin(forward, forwardSpeed + sideSpeed, percent);

    rightWheels.spin(forward, forwardSpeed - sideSpeed, percent);

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}