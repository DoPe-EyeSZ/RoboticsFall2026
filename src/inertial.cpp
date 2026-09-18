#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include <cmath>

void turnRight(){
    const double target = InertialSensor.rotation(deg) + 90;
    const double Kp = 0.35;
    const double Kd = 0;

    double err = 0;
    double prevErr = 0;

    double currDeg;
    double derivative;
    double motorPow;
    timer t; 
    t.reset(); 

    while (t.time(sec) < 1.5){
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
        wait(1, msec);
        
    }
    leftWheels.stop();
    rightWheels.stop();
}

void turnLeft(){
    const double target = InertialSensor.rotation(deg) - 90;
    const double Kp = 0.375;
    const double Kd = 0.0;

    double err = 0;
    double prevErr = 0;

    double currDeg;
    double derivative;
    double motorPow;
    timer t; 
    t.reset(); 
    while (t.time(sec) < 1.5){
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
        wait(1, msec);
        
    }
    leftWheels.stop();
    rightWheels.stop();
}