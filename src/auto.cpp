

#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include "odometry.h"
#include "vision.h"
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 

    /*turnLeft(180);
    turnRight(180);
    turnLeft(90);
    turnRight(90);*/
    //driveDistance(50.0, 5);
    
    //driveDistance(100.0, 5.0);
    //Vision();
    
    //Vision(); // Call the Vision function to align the robot with the colored pin
    /*turnRight(90);
    turnLeft(90);
    turnRight(180);
    turnLeft(180);
    */


}