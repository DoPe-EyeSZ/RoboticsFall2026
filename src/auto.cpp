

#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include "odometry.h"
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 

    //turnLeft(180);
    //turnRight(180);
    //turnLeft(90);
    //turnRight(90);
    driveDistance(100.0, 5.0);
    driveDistance(-100.0, 5.0);

}