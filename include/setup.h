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
extern vex::motor liftMotorLeftBottom;
extern vex::motor liftMotorRightBottom;
extern vex::motor liftMotorLeftTop;
extern vex::motor liftMotorRightTop;

// Claw motor
extern vex::motor clawMotor;

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

//Brain
extern vex::brain Brain;

//Vision Sensor
extern vex::vision VisionSensor;


#endif

