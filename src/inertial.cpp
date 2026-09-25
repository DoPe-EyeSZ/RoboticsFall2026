#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include <cmath>

void turnRight(int degree){
    const double target = InertialSensor.rotation(deg) + degree;
    const double Kp = 0.32;
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

        //Motor power clamp
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        if (fabs(err) < 1){
            break;
        }
        wait(20, msec);
        
    }
    leftWheels.setStopping(brakeType::coast);
    rightWheels.setStopping(brakeType::coast);
    leftWheels.stop();
    rightWheels.stop();
}

void turnLeft(int degree){
    const double target = InertialSensor.rotation(deg) - degree;
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

        //Motor power clamp
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        if (fabs(err) < 1){
            break;
        }
        wait(20, msec);
        
    }
    leftWheels.stop();
    rightWheels.stop();
}