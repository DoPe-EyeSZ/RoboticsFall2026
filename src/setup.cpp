
#include "vex.h"
#include "setup.h"

vex::motor rightMotorFront(vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor leftMotorFront(vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor rightMotorBack(vex::PORT13, vex::gearSetting::ratio18_1, false);
vex::motor leftMotorBack(vex::PORT12, vex::gearSetting::ratio18_1, false);
vex::controller Controller1(vex::controllerType::primary);