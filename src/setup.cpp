
#include "vex.h"
#include "setup.h"

// Front motors
vex::motor rightMotorFront(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor leftMotorFront(vex::PORT12, vex::gearSetting::ratio18_1, false);

// Back motors
//vex::motor rightMotorBack(vex::PORT__, vex::gearSetting::ratio18_1, true);
//vex::motor leftMotorBack(vex::PORT__, vex::gearSetting::ratio18_1, false);

// Grouping motors
vex::motor_group leftWheels(leftMotorFront, leftMotorBack);
vex::motor_group rightWheels(rightMotorFront, rightMotorBack);

// Grouping lift motors
//vex::motor liftMotorLeft(vex::PORT__, vex::gearSetting::ratio18_1, true);
//vex::motor liftMotorRight(vex::PORT__, vex::gearSetting::ratio18_1, false);
//vex::motor_group liftMotors(liftMotorLeft, liftMotorRight);

// Inertial Sensor
vex::inertial InertialSensor(vex::PORT13);

//Odometry
vex::rotation RotationSensor(vex::PORT4, false);

//Vision sensor
//vex::vision VisionSensor(vex::PORT__);

// Drive Train
vex::drivetrain driveTrain(leftWheels, rightWheels);

//configure controller
vex::controller Controller1(vex::controllerType::primary);

//configure V5 brain
vex::brain Brain;