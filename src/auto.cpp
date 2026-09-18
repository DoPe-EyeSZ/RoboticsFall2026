

#include "vex.h"
#include "setup.h"
#include <cmath>

brain Brain;

void turnRight(){
    const double target = InertialSensor.rotation(deg) + 90;
    const double Kp = 0.5;
    const double Kd = 0.5;

    double err = 0;
    double prevErr = 0;

    double currDeg;
    double derivative;
    double motorPow;

    while (true){
        currDeg = InertialSensor.rotation(deg);

        err = target - currDeg;

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        if (fabs(err) < 1){
            break;
        }
        wait(10, msec);
        
    }
    leftWheels.stop();
    rightWheels.stop();
}

void turnLeft(){
    const double target = InertialSensor.rotation(deg) - 90;
    const double Kp = 0.5;
    const double Kd = 0.5;

    double err = 0;
    double prevErr = 0;

    double currDeg;
    double derivative;
    double motorPow;

    while (true){
        currDeg = InertialSensor.rotation(deg);

        err = target - currDeg;

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        if (fabs(err) < 1){
            break;
        }
        wait(10, msec);
        
    }
    leftWheels.stop();
    rightWheels.stop();
}

void autonomous() {

    InertialSensor.setRotation(0, deg); // Reset the head of Inertial Sensor to 0 degrees 
    driveTrain.setTurnVelocity(20, percent);


    turnLeft();





}