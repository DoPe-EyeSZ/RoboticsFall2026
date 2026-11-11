#include "vex.h"
#include "setup.h"
#include "routine.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>

using namespace std;

void autonomous() {
    //Reset banshee claw position
    bansheeMotor.setStopping(vex::brakeType::hold);
    if (fabs(bansheeMotor.position(vex::rotationUnits::deg)) < 360) {
        bansheeMotor.spinToPosition(-345, vex::rotationUnits::deg, 50,
                                    vex::velocityUnits::pct, true);
    }
    bansheeMotor.stop(vex::brakeType::hold);
    InertialSensor.setRotation(0, deg);

    //CHANGE ON MATCH
    const string color = "yellow";      //color to target (red, yellow, blue)
    const double tileDistance = 60.96;     //cm
    const string mode = "test";         //skills (2 teammates), match (2v2), test 

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
