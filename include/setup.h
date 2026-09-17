#ifndef SETUP_H
#define SETUP_H

#include "vex.h"

using namespace vex;

// Front motors
extern vex::motor rightMotorFront;
extern vex::motor leftMotorFront;

// Back motors
extern vex::motor rightMotorBack;
extern vex::motor leftMotorBack;

// Grouping motors
extern vex::motor_group leftWheels;
extern vex::motor_group rightWheels;

// Lifting motors
extern vex::motor liftMotorLeft;
extern vex::motor liftMotorRight;

// Inertial Sensor
extern vex::inertial InertialSensor;

//Odometry sensor
extern vex::rotation RotationSensor;

// Drive Train
extern vex::drivetrain driveTrain;

// Grouping lift motors
extern vex::motor_group liftMotors;

// Controller
extern vex::controller Controller1;

#endif

