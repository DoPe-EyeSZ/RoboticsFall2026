
#include "vex.h"
#include "setup.h"

// Front motors
vex::motor rightMotorFront(vex::PORT14, vex::gearSetting::ratio18_1, true);
vex::motor leftMotorFront(vex::PORT11, vex::gearSetting::ratio18_1, false);

// Back motors
vex::motor rightMotorBack(vex::PORT13, vex::gearSetting::ratio18_1, true);
vex::motor leftMotorBack(vex::PORT12, vex::gearSetting::ratio18_1, false);

// Grouping motors
vex::motor_group leftWheels(leftMotorFront, leftMotorBack);
vex::motor_group rightWheels(rightMotorFront, rightMotorBack);

// Grouping lift motors
vex::motor liftMotorLeft(vex::PORT16, vex::gearSetting::ratio18_1, true);
vex::motor liftMotorRight(vex::PORT17, vex::gearSetting::ratio18_1, false);
vex::motor_group liftMotors(liftMotorLeft, liftMotorRight);

// Inertial Sensor
vex::inertial InertialSensor(vex::PORT20);

//Odometry
vex::rotation RotationSensor(vex::PORT4, false);

// Drive Train
vex::drivetrain driveTrain(leftWheels, rightWheels);

//configure controller
vex::controller Controller1(vex::controllerType::primary);

//configure V5 brain
vex::brain Brain;