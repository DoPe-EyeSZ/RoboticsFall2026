#include "vex.h"
#include "setup.h"


// User control code here, inside the loop
void usercontrol() {

  while (1) {
    //Get speed from controller joysticks
    int forwardSpeed = Controller1.Axis3.position();   //left joystick output (forward/backward)
    int sideSpeed = Controller1.Axis1.position();    //right joystick output (left/right)

    leftWheels.spin(forward, forwardSpeed + sideSpeed, percent);
    leftWheels.setStopping(brakeType::coast);

    rightWheels.spin(forward, forwardSpeed - sideSpeed, percent);
    rightWheels.setStopping(brakeType::coast);

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}