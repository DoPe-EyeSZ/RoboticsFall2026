#include "vex.h"
#include "setup.h"


// User control code here, inside the loop
void usercontrol() {

  leftWheels.setStopping(brakeType::coast);
  rightWheels.setStopping(brakeType::coast);

  while (1) {

    //Get speed from controller joysticks
    int forwardSpeed = Controller1.Axis3.position();   //left joystick output (forward/backward)
    int sideSpeed = Controller1.Axis1.position();    //right joystick output (left/right)

    
    //if (Controller1.ButtonR2.pressing()) {    //Motor going up
    //  liftMotors.spin(forward, 100, percent);
    //} 
    //else if (Controller1.ButtonL2.pressing()) {   //Motor going down
    //  liftMotors.spin(reverse, 100, percent);
    //} 

    leftWheels.spin(forward, forwardSpeed + sideSpeed, percent);

    rightWheels.spin(forward, forwardSpeed - sideSpeed, percent);

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}