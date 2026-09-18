/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ryeun                                                     */
/*    Created:      9/11/2026, 10:54:14 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "setup.h"
#include "pre-auto.h"
#include "auto.h"
#include "odometry.h"
#include "control.h"

using namespace vex;

// A global instance of competition
competition Competition;

int main() {
  //tells program to listen for sign to run autonomous, autonomous odometry, and usercontrol function
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
