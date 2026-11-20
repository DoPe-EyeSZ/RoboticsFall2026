#include "mechanical.h"
#include "setup.h"
//#include "inertial.h" - not being used right now
#include "odometry.h"
#include <cmath>

namespace {

//Pin processing constants
constexpr double kBansheeUprightAngle = -345.0; //degrees
constexpr double maxLiftAngle = 224.0; //degrees

void collectPin() {
    claw("in"); //Collects pin
}

void moveClawUpright() {
    clawMotor.spinToPosition(0, vex::rotationUnits::deg, 100,
                             vex::velocityUnits::pct, true); //Moves banshee claw to upright position
}

void releasePin() {
    clawMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct); //Releases pin
    wait(0.15, vex::sec); //Small delay
    clawMotor.stop();
}

void resetClaw() {
    //Reset banshee claw position
    clawMotor.setStopping(vex::brakeType::hold);
    if (std::fabs(clawMotor.position(vex::rotationUnits::deg)) < 360) { //Fix this magic number
        clawMotor.spinToPosition(kBansheeUprightAngle, vex::rotationUnits::deg,
                                 50, vex::velocityUnits::pct, true);
    }
    clawMotor.stop(vex::brakeType::hold);
    //release pin with backward rotation of the claw roller
    //reset banshee claw to the downmost position
}

}


// Assume bot is front-facing already
void flipBar(std::string color) {
    
    // Flip bar 1x
    if (color == "blue") {
        claw("out");
        driveDistance(50);

    }
    // Flip bar 2x 
    else {
        claw("out");
        driveDistance(200, 1);
        driveDistance(-100, .75);
        driveDistance(100, 1);

    }
}

void lift(std::string action) {
    //pick something up with claw
    if (action == "up") {
        liftMotors.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }

    //drop what is being held
    else if (action == "down") {
        liftMotors.spin(vex::directionType::rev, 25, vex::velocityUnits::pct);
    }
}

void claw(std::string direction) {
    if (direction == "in") {
        //claw roller collects pin
        clawMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        wait(0.5, vex::sec);
        clawMotor.stop();
    }
    else if (direction == "out") {
        //outtake roller releases pin
        clawMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        wait(0.5, vex::sec);
        clawMotor.stop();
    }
}

void processPin() {
    //some pseudo-pseudo code to plan the function logic
    //always reset banshee claw to the downmost position after every programming skills match
    //after a short delay of the claw roller collecting the pin, lift the claw up to be perpendicular to the ground using motors' rotation sensors
    collectPin();
    moveClawUpright();
    releasePin();
    resetClaw();
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

void liftDown(double spinPercent){
    liftMotors.spin(vex::directionType::rev, spinPercent, vex::velocityUnits::pct);
}