/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

#include "vex.h"
#include "setup.h"


// User control code here, inside the loop
void usercontrol() {

  while (1) {
    //Get speed from controller joysticks
    int forwardSpeed = Controller1.Axis3.position();   //left joystick input (forward/backward)
    int sideSpeed = Controller1.Axis1.position();    //right joystick input (left/right)

    leftWheels.spin(forward, forwardSpeed + sideSpeed, percent);
    leftWheels.setStopping(brakeType::coast);

    rightWheels.spin(forward, forwardSpeed - sideSpeed, percent);
    rightWheels.setStopping(brakeType::coast);

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}