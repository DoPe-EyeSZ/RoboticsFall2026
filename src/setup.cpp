
#include "vex.h"
#include "setup.h"

//configure motors
vex::motor rightMotorFront(vex::PORT14, vex::gearSetting::ratio18_1, false);

vex::motor leftMotorFront(vex::PORT11, vex::gearSetting::ratio18_1, false);

vex::motor rightMotorBack(vex::PORT13, vex::gearSetting::ratio18_1, false);

vex::motor leftMotorBack(vex::PORT12, vex::gearSetting::ratio18_1, false);

//grouping motors
vex::motor_group leftWheels(leftMotorFront, leftMotorBack);
vex::motor_group rightWheels(rightMotorFront, rightMotorBack);

//configure controller
vex::controller Controller1(vex::controllerType::primary);