

#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include "odometry.h"
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 

    driveDistance(100.0, 5.0);
    

}