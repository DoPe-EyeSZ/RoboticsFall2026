#include "vex.h"
#include "setup.h"
#include <cmath>
#include <string>

using namespace std;

namespace {

//Pin processing constants
constexpr double bansheeUprightAngle = -345.0; //degrees

}

void flipBar(string color) {
    if (color == "red") {
        //lift 1x;
    } 
    else {
        //lift 2x;
    }
}

void elevator(string action) {
    //pick something up with claw
    if (action == "up") {
        //lift actions
    } 

    //drop what is being held
    else if (action == "down") {
        //lower actions
    }
}

void intake(string direction)
{
    if (direction == "in") {
        //intake roller collects pin
        intakeMotors.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        wait(0.5, vex::sec);
        intakeMotors.stop();
    } 
    else if (direction == "out") {
        //outtake roller releases pin
        intakeMotors.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        wait(0.5, vex::sec);
        intakeMotors.stop();
    }
}

void processPin() {
    //some pseudo-pseudo code to plan the function logic
    //always reset banshee claw to the downmost position after every programming skills match
    //after a short delay of the intake roller collecting the pin, lift the claw up to be perpendicular to the ground using motors' rotation sensors
    intake("in"); //Collects pin
    bansheeMotor.spinToPosition(0, vex::rotationUnits::deg, 100, vex::velocityUnits::pct, true); //Moves banshee claw to upright position
    intakeMotors.spin(vex::directionType::rev, 100, vex::velocityUnits::pct); //Releases pin
    wait(0.15, vex::sec); //Small delay
    intakeMotors.stop();
    //Reset banshee claw position
    bansheeMotor.setStopping(vex::brakeType::hold);
    if (fabs(bansheeMotor.position(vex::rotationUnits::deg)) < 360) { //Fix this magic number
        bansheeMotor.spinToPosition(bansheeUprightAngle, vex::rotationUnits::deg, 50,
                                    vex::velocityUnits::pct, true);
    }
    bansheeMotor.stop(vex::brakeType::hold);
    //release pin with backward rotation of the intake roller
    //reset banshee claw to the downmost position
}