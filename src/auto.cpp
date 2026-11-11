#include "vex.h"
#include "setup.h"
#include "routine.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>

using namespace std;


void autonomous() {
    if (InertialSensor.isCalibrating()) {
        while (InertialSensor.isCalibrating()) {
            wait(25, msec);
        }
    }
    bansheeMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct); 
    //Reset banshee claw position
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
