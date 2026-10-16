

#include "vex.h"
#include "setup.h"
//#include "inertial.h" - not being used right now
//#include "odometry.h" - not being used right now
//#include "vision.h" - not being used right now
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(value: 0, units: deg); // Reset the head of Inertial Sensor to 0 degrees 

    driveDistance(100.0, 5.0);
    

}