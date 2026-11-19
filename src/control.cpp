#include "vex.h"
#include "setup.h"
#include "mechanical.h"

// User control code here, inside the loop
void usercontrol() {
  leftWheels.setStopping(brakeType::coast);
  rightWheels.setStopping(brakeType::coast);
  liftMotors.setStopping(brakeType::hold);
  clawMotor.setStopping(brakeType::hold);
  Controller1.ButtonR2.pressed(openClaw);
  Controller1.ButtonL2.pressed(closeClaw);

  while (true) {
    //Get speed from controller joysticks
    int forwardSpeed = -Controller1.Axis3.position(); //left joystick output (forward/backward)
    forwardSpeed = (forwardSpeed * forwardSpeed * forwardSpeed) / 10000;
    int sideSpeed = -Controller1.Axis1.position(); //right joystick output (left/right)


    //incrase power of lift motors to make it more responsive



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