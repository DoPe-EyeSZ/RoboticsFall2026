

#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include "odometry.h"
//#include "vision.h" - not being used right now
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 

<<<<<<< HEAD
    turnLeft(90);
    turnRight(90);
    
=======
    driveDistance(100.0, 5.0);
    turnLeft(180);
    driveDistance(50.0, 5.0);
    turnLeft(90);
    driveDistance(50.0, 5.0);
    turnLeft(90);
    driveDistance(50.0, 5.0);
>>>>>>> d307df715e20b5cac8c8495d307ec6a0bc7f2999

}