/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ryeun                                                     */
/*    Created:      9/11/2026, 10:54:14 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
//#include "setup.h" - not being used right now
#include "pre-auto.h"
#include "auto.h"
//#include "odometry.h" - not being used right now
#include "control.h"

using namespace vex;

// A global instance of competition
competition Competition;

namespace {

void registerCompetitionCallbacks() {
  //tells program to listen for sign to run autonomous, autonomous odometry, and usercontrol function
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
}

}

int main() {
  registerCompetitionCallbacks();
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
