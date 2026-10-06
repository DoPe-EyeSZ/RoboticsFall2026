

#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include "odometry.h"
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 

    driveDistance(50.0, 5.0);
    driveDistance(-50.0, 5.0);

    driveDistance(50.0, 5.0);
    turnRight(90.0);
    driveDistance(50.0, 5.0);
    turnRight(90.0);
    driveDistance(50.0, 5.0);
    turnRight(90.0);
    driveDistance(50.0, 5.0);
    turnRight(90.0);

    turnLeft(90.0);
    driveDistance(-50.0, 5.0);
    turnLeft(90.0);
    driveDistance(-50.0, 5.0);
    turnLeft(90.0);
    driveDistance(-50.0, 5.0);
    turnLeft(90.0);
    driveDistance(-50.0, 5.0);
    
}