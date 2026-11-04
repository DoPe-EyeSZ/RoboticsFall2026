
#include "vex.h"
#include "setup.h"

// Front motors
vex::motor rightMotorFront(vex::PORT19, vex::gearSetting::ratio18_1, true);
vex::motor leftMotorFront(vex::PORT13, vex::gearSetting::ratio18_1, false);

// Middle motors
vex::motor rightMotorMiddle(vex::PORT16, vex::gearSetting::ratio18_1, true);
vex::motor leftMotorMiddle(vex::PORT12, vex::gearSetting::ratio18_1, false);

// Back motors
vex::motor rightMotorBack(vex::PORT15, vex::gearSetting::ratio18_1, true);
vex::motor leftMotorBack(vex::PORT11, vex::gearSetting::ratio18_1, false);

// Grouping motors
vex::motor_group leftWheels(leftMotorFront, leftMotorMiddle, leftMotorBack);
vex::motor_group rightWheels(rightMotorFront, rightMotorMiddle, rightMotorBack);

// Grouping lift motors
vex::motor liftMotorLeft(vex::PORT9, vex::gearSetting::ratio18_1, true);
vex::motor liftMotorRight(vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor_group liftMotors(liftMotorLeft, liftMotorRight);

// Intake motor
vex::motor intakeMotor(vex::PORT17, vex::gearSetting::ratio18_1, true);
vex::motor intakeMotor2(vex::PORT7, vex::gearSetting::ratio18_1, true);
vex::motor_group intakeMotors(intakeMotor, intakeMotor2);

// Banshee motor
vex::motor bansheeMotor(vex::PORT6, vex::gearSetting::ratio18_1, true);

// Inertial Sensor
vex::inertial InertialSensor(vex::PORT20);

//Odometry
vex::rotation RotationSensor(vex::PORT5, false);

// Drive Train
vex::drivetrain driveTrain(leftWheels, rightWheels);

//configure controller
vex::controller Controller1(vex::controllerType::primary);

//configure V5 brain
vex::brain Brain;

//configure vision sensor
vex::vision VisionSensor(vex::PORT8);