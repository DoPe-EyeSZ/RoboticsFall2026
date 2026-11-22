#include "mechanical.h"
#include "setup.h"
//#include "inertial.h" - not being used right now
#include "odometry.h"
#include <cmath>

namespace {
//Pin processing constants
constexpr double maxLiftAngle = 250.0; //degrees
constexpr double minLiftAngle = 100.0; //degrees


}


// Assume bot is front-facing already
void flipBar(std::string color) {
    autoCloseClaw();
    // Flip bar 1x
    if (color == "blue") {
        driveDistance(50);

    }
    // Flip bar 2x 
    else {
        driveDistance(200, 1);
        driveDistance(-100, .75);
        driveDistance(100, 1);

    }
}


void lift(std::string action, double maxTime) {
    timer t;
    t.reset();

    if (action == "up") {
        liftMotors.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
        while (std::fabs(liftMotors.position(vex::rotationUnits::deg)) < maxLiftAngle && t.time(sec) < maxTime) {
            wait(10, msec);   // don't hog the CPU
        }
        liftMotors.stop();
    }
    else if (action == "down") {
        liftMotors.spin(vex::directionType::rev, 25, vex::velocityUnits::pct);
        while (std::fabs(liftMotors.position(vex::rotationUnits::deg)) > minLiftAngle && t.time(sec) < maxTime) {
            wait(10, msec);
        }
        liftMotors.stop();
    }
}

void autoCloseClaw() {
    clawMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    wait(0.5, vex::sec);
    clawMotor.stop();
}

void autoOpenClaw() {
    clawMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    wait(0.5, vex::sec);
}

void processPin() {
    //some pseudo-pseudo code to plan the function logic
    //always reset banshee claw to the downmost position after every programming skills match
    //after a short delay of the claw roller collecting the pin, lift the claw up to be perpendicular to the ground using motors' rotation sensors
    
}

// Functions for MANUAL CONTROL ONLY
void openClaw(){
    clawMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
}

void closeClaw(){
    clawMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
}

void liftUp(double spinPercent){
    liftMotors.spin(vex::directionType::fwd, spinPercent, vex::velocityUnits::pct);
}

void liftDown(){
    liftMotors.spin(vex::directionType::rev, 25, vex::velocityUnits::pct);
}