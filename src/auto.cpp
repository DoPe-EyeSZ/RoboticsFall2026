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
    if (action == "up") {
        //lift actions
    } 
    else if (action == "down") {
        //lower actions
    }
}

void autonomous() {
    InertialSensor.setRotation(0, deg); 

    //CHANGE ON MATCH
    const string color = "red"; 
    const int tileDistance = 61; //cm

    //skills mode: teammates only; whole field
    //head to head mode: 2 teams; half field;

    //Below is skills mode

    //Flipping bar thing
    turnRight(180);
    flipBar(color);

    //Drive to the pin
    turnRight(90);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnRight(85);


}