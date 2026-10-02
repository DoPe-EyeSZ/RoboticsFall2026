#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include <cmath>

void turnRight(int degree){
    //kp, kd, target values initialization
    const double target = InertialSensor.rotation(deg) + degree;
    const double Kp = 0.35;
    const double Kd = 0.05;

    double err = 0;
    double prevErr = 0;

    //initialize variables for PID control
    double currDeg;
    double derivative;
    double motorPow;

    //initialize timer
    timer t; 
    t.reset(); 

    while (t.time(sec) < 1.2){
        currDeg = InertialSensor.rotation(deg);

        err = target - currDeg;

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        //Motor power cap
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        // Stop spinning if error is within 0.5 degrees of target
        if (fabs(err) < 0.5){
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
    const double Kp = 0.335;
    const double Kd = 0.05;

    double err = 0;
    double prevErr = 0;

    double currDeg;
    double derivative;
    double motorPow;
    timer t; 
    t.reset(); 
    while (t.time(sec) < 1.2){
        currDeg = InertialSensor.rotation(deg);

        err = target - currDeg;

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        //Motor power cap
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        if (fabs(err) < 0.5){
            break;
        }
        wait(20, msec);
        
    }
    leftWheels.setStopping(brakeType::coast);
    rightWheels.setStopping(brakeType::coast);
    leftWheels.stop();
    rightWheels.stop();
}