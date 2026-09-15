/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


#include "vex.h"
#include "setup.h"


void autonomous() {
    InertialSensor.setHeading(0, rotationUnits::deg); // Reset the head of Inertial Sensor to 0 degrees


    driveTrain.turnFor(right, 60, deg); // Turn to 90 degrees

  

}