#include "vex.h"
#include "setup.h"
#include "inertial.h"
#include "odometry.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>

using namespace std;
void flipBar(string color) {
    if (color == "red") {
        //lift 1x;
    } 
    else {
        //lift 2x;
    }
}

void autonomous() {
    InertialSensor.setRotation(0, deg); 

    //CHANGE ON MATCH
    const string color = "red"; 
    const int tileDistance = 61; //cm

    //Flipping bar thing
    turnRight(180);
    flipBar(color);

    //Drive to the pin
    turnRight(90);
    driveDistance(tileDistance*0.9, 3.0);
    turnRight(85);


}