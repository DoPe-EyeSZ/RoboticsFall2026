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

//Skills mode; do half of field
void skillsMode(string color, double tileDistance){

    //Flipping bar thing
    turnRight(180);
    flipBar(color);

    //Stack first base
    turnRight(90);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnRight(85);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("down");
    turnLeft(175);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("down");
    turnLeft(175);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("down");
}