/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ryeun                                                     */
/*    Created:      9/11/2026, 10:54:14 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "pre-auto.h"
#include "auto.h"
#include "control.h"
#include "setup.h"

using namespace vex;

// A global instance of competition
competition Competition;


int main() {
  //tells program to listen for sign to run autonomus and usercontrol function
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Calibrate the Inertial Sensor



  // Run the pre-autonomous function.
  //pre_auton();
  //usercontrol();    //DELETE LATER, USE FOR TESTING PURPOSES ONLY
  autonomous();    //DELETE LATER, USE FOR TESTING PURPOSES ONLY


  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
