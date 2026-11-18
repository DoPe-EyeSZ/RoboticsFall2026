#include "vex.h"
#include "setup.h"
#include "mechanical.h"

// User control code here, inside the loop
void usercontrol() {
  leftWheels.setStopping(brakeType::coast);
  rightWheels.setStopping(brakeType::coast);
  liftMotors.setStopping(brakeType::hold);
  clawMotor.setStopping(brakeType::hold);

  while (true) {
    //Get speed from controller joysticks
    int forwardSpeed = -Controller1.Axis3.position(); //left joystick output (forward/backward)
    forwardSpeed = (forwardSpeed * forwardSpeed * forwardSpeed) / 10000;
    int sideSpeed = -Controller1.Axis1.position(); //right joystick output (left/right)

    //Control claw motors
    if (Controller1.ButtonR2.pressing()) {
      openClaw();
    } else if (Controller1.ButtonL2.pressing()) {
      closeClaw();
    } else {
      clawMotor.stop();
    }

    //Control lift motor
    if (Controller1.ButtonB.pressing()) {
      liftUp();
    } else if (Controller1.ButtonA.pressing()) {
      liftDown();
    } else {
      liftMotors.stop();
    }

    leftWheels.spin(vex::directionType::fwd, forwardSpeed + sideSpeed,
                    vex::velocityUnits::pct);
    rightWheels.spin(vex::directionType::fwd, forwardSpeed - sideSpeed,
                     vex::velocityUnits::pct);

    wait(20, vex::msec); // Sleep the task for a short amount of time to
  }
}