#include "vex.h"
#include "setup.h"

void openClaw(){
  clawMotor.spin(forward, 100, percent);
 
}

void closeClaw(){
  clawMotor.spin(reverse, 100, percent);
}

void liftUp(){
  liftMotors.spin(forward, 100, percent);
}

void liftDown(){
  liftMotors.spin(reverse, 25, percent);
}

// User control code here, inside the loop
void usercontrol() {

  leftWheels.setStopping(brakeType::coast);
  rightWheels.setStopping(brakeType::coast);
  liftMotors.setStopping(brakeType::hold);
  clawMotor.setStopping(brakeType::hold);

  while (1) {

    //Get speed from controller joysticks
    int forwardSpeed = -Controller1.Axis3.position();   //left joystick output (forward/backward)
    forwardSpeed = (forwardSpeed*forwardSpeed*forwardSpeed)/10000; 
    int sideSpeed = -Controller1.Axis1.position();    //right joystick output (left/right)

    //Control claw motors 
    if (Controller1.ButtonR2.pressing()) {
      openClaw();
    }
    else if (Controller1.ButtonL2.pressing()) {
      closeClaw();
    }
    else {
      clawMotor.stop();
    }

    //Control lift motor
    if (Controller1.ButtonB.pressing()) {
      liftUp();
    }
    else if (Controller1.ButtonA.pressing()) {
      liftDown();
    }
    else {
      liftMotors.stop();
    }

    leftWheels.spin(forward, forwardSpeed + sideSpeed, percent);

    rightWheels.spin(forward, forwardSpeed - sideSpeed, percent);

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}