#include "vex.h"
#include "setup.h"
#include "routine.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>

using namespace std;


void autonomous() {
    InertialSensor.setRotation(0, deg); 

    //CHANGE ON MATCH
    const string color = "red"; 
    const double tileDistance = 61; //cm
    const string mode = "skills";

    if (mode == "skills"){
        skillsMode(color, tileDistance);
    }


}