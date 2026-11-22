#include "vex.h"
#include "mechanical.h"
#include "setup.h"
#include "routine.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>

using namespace std;

//Pin processing constants
constexpr double bansheeUprightAngle = -345.0; //degrees

void autonomous() {
    autoOpenClaw();
    clawMotor.setStopping(vex::brakeType::hold);
    clawMotor.stop(vex::brakeType::hold);
    liftMotors.setStopping(vex::brakeType::hold);
    InertialSensor.setRotation(0, deg);

    //CHANGE ON MATCH
    const string teamColor = "yellow";      //color to target (red, yellow, blue)
    const double tileDistance = 60.96;     //cm
    const string mode = "test";         //"skills" (2 teammates), "match" (2v2), "test"

    if (mode == "skills"){
        skillsMode(teamColor, tileDistance);
    }
    if (mode == "match"){
        matchMode(teamColor, tileDistance);
    }
    if (mode == "test"){
        testMode(teamColor, tileDistance);
    }
}
