

#include "vex.h"
#include "setup.h"

brain Brain;

void turnRight(){
    double currDeg = InertialSensor.rotation(deg);
    while (abs(InertialSensor.rotation(deg)-currDeg) < 60){
        driveTrain.turn(right);
    }
    driveTrain.stop();
}

void turnLeft(){
    double currDeg = InertialSensor.rotation(deg);
    while (abs(currDeg - InertialSensor.rotation(deg)) < 60){
        driveTrain.turn(left);
    }
    driveTrain.stop();
}

void autonomous() {

    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 
    driveTrain.setTurnVelocity(20, percent);


    turnRight();

    turnLeft();

    turnRight();

    turnLeft();


}