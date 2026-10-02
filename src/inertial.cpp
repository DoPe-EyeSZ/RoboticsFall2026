#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include <cmath>

void turnRight(int degree){
    //kp, kd, target values initialization
    const double target = InertialSensor.rotation(deg) + degree;
    const double Kp = 0.40;
    const double Kd = 0.00;

    double err;
    double prevErr = target - InertialSensor.rotation(deg);

    //initialize variables for PID control
    double derivative;
    double motorPow;

    //initialize timer
    timer t; 
    t.reset(); 

    while (t.time(sec) < 1.2){
                
        err = target - InertialSensor.rotation(deg);

        if (fabs(err) < 1) break;   // check if the error is within a threshold to break the loop

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        //Motor power cap
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        wait(18, msec);
        
    }
    leftWheels.stop(brakeType::hold);
    rightWheels.stop(brakeType::hold);

}



void turnLeft(int degree){
    //kp, kd, target values initialization
    const double target = InertialSensor.rotation(deg) - degree;
    const double Kp = 0.40;
    const double Kd = 0.00;

    double err;
    double prevErr = target - InertialSensor.rotation(deg);

    //initialize variables for PID control
    double derivative;
    double motorPow;

    //initialize timer
    timer t; 
    t.reset(); 

    while (t.time(sec) < 1.2){

        err = target - InertialSensor.rotation(deg);

        if (fabs(err) < 1) break;   // check if the error is within a threshold to break the loop

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        //Motor power cap
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        wait(18, msec);
        
    }
    leftWheels.stop(brakeType::hold);
    rightWheels.stop(brakeType::hold);
}