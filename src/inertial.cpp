#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include <cmath>

void turn(int degree){
    //kp, kd, startingAngle values initialization
    const double startingAngle = InertialSensor.rotation(deg);
    const double Kp = 0.55;
    const double Kd = 0.1;

    double err;
    double prevErr = 0;

    //initialize variables for PID control
    double derivative;
    double motorPow;

    //initialize timer
    timer t; 
    t.reset(); 

    while (t.time(sec) < 1.2){
                
        err = InertialSensor.rotation(deg) - degree - startingAngle;

        if (fabs(err) < 0.5) break;   // check if the error is within a threshold to break the loop

        derivative = err - prevErr;

        motorPow = (Kp*err) + (Kd*derivative);

        //Motor power cap
        if (motorPow > 100.0) motorPow = 100.0;
        if (motorPow < -100.0) motorPow = -100.0;

        leftWheels.spin(forward, motorPow, percent);
        rightWheels.spin(reverse, motorPow, percent);

        prevErr = err;

        wait(10, msec);
        
    }
    leftWheels.stop(brakeType::hold);
    rightWheels.stop(brakeType::hold);

}

