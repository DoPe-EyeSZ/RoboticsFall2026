

#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include <cmath>




void autonomous() {
    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 
    driveTrain.setTurnVelocity(20, percent);

    turnRight(90);
    turnLeft(90);
    turnRight(180);
    turnLeft(180);


}