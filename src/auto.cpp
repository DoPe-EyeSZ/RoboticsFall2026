#include "vex.h"
#include "setup.h"
#include "routine.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>

using namespace std;

//Pin processing constants
constexpr double bansheeUprightAngle = -345.0; //degrees

void autonomous() {
    //Reset banshee claw position
    clawMotor.setStopping(vex::brakeType::hold);
    if (fabs(clawMotor.position(vex::rotationUnits::deg)) < 360) { //Fix this magic number
        clawMotor.spinToPosition(bansheeUprightAngle, vex::rotationUnits::deg, 50,
                                    vex::velocityUnits::pct, true);
    }
    clawMotor.stop(vex::brakeType::hold);
    InertialSensor.setRotation(0, deg);

    //CHANGE ON MATCH
    const string color = "yellow";      //color to target (red, yellow, blue)
    const double tileDistance = 60.96;     //cm
    const string mode = "test";         //"skills" (2 teammates), "match" (2v2), "test"

    if (mode == "skills"){
        skillsMode(color, tileDistance);
    }
    if (mode == "match"){
        matchMode(color, tileDistance);
    }
    if (mode == "test"){
        testMode(color, tileDistance);
    }
}
