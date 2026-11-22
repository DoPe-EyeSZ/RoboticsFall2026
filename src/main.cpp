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
//#include "pre-auto.h"
#include "auto.h"
//#include "odometry.h" - not being used right now
#include "control.h"

using namespace vex;

competition Competition;

namespace {

void registerCompetitionCallbacks() {
  //Listen for flags
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
}

}

int main() {
  //pre_auton();
  registerCompetitionCallbacks();


  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
