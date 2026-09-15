#ifndef SETUP_H
#define SETUP_H

#include "vex.h"

using namespace vex;

// Creating motor and controller objects
extern vex::motor rightMotorFront;
extern vex::motor leftMotorFront;

extern vex::motor rightMotorBack;
extern vex::motor leftMotorBack;

extern vex::motor_group leftWheels;
extern vex::motor_group rightWheels;

//lifting motors
extern vex::motor liftMotorLeft;
extern vex::motor liftMotorRight;

extern vex::motor_group liftMotors;

extern vex::controller Controller1;

#endif

