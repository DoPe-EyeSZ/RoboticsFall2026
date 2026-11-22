#include "mechanical.h"
#include "setup.h"
//#include "inertial.h" - not being used right now
#include "odometry.h"
#include <cmath>

namespace {
//Pin processing constants
constexpr double maxLiftAngle = 300.0; //degrees
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
    //pick something up with claw

    timer t;
    t.reset();

    if (action == "up") {
        liftMotors.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);

        if (std::fabs(liftMotors.position(vex::rotationUnits::deg)) >= maxLiftAngle || t.time(sec) >= maxTime) {
            Controller1.Screen.newLine();
            Controller1.Screen.print(liftMotors.position(rotationUnits::deg));
            liftMotors.stop();
            Controller1.Screen.print(liftMotors.position(rotationUnits::deg));
            return;
        }

    }

    //drop what is being held
    else if (action == "down") {
    if (std::fabs(liftMotors.position(vex::rotationUnits::deg)) < minLiftAngle) {
        liftMotors.stop();
    }
    liftMotors.spin(vex::directionType::rev, 25, vex::velocityUnits::pct);
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