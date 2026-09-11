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

brain Brain;

void usercontrol() {
  // User control code here, inside the loop
  while (1) {
    
    //get speed from controller joysticks
    int forwardSpeed = Controller1.Axis3.position();   //forward & back
    int sideSpeed = Controller1.Axis1.position();    //left & right

    //front motors
    leftMotorFront.spin(forward, sideSpeed + forwardSpeed, percent);
    rightMotorFront.spin(forward, sideSpeed - forwardSpeed, percent);
    leftMotorFront.setBrake(brakeType::coast);
    rightMotorFront.setBrake(brakeType::coast);

    //back motors
    leftMotorBack.spin(forward, sideSpeed + forwardSpeed, percent);
    rightMotorBack.spin(forward, sideSpeed - forwardSpeed, percent);
    leftMotorBack.setBrake(brakeType::coast);
    rightMotorBack.setBrake(brakeType::coast);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}