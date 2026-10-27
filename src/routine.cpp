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


    //Trip 1 (stack grey thing on base)
    turnRight(90);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnRight(85);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("down");

    //Trip 2 (stack yellow cone on grey thing)
    turnLeft(175);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("down");

    //Trip 3 (stack grey thing on yellow)
    turnLeft(175);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9, 3.0);
    elevator("down");

    //Trip 4 (stack yellow gone on grey)
    turnLeft(85);
    driveDistance(tileDistance*0.3);
    elevator("up");
    turnRight(160);
    driveDistance(tileDistance*0.3);
    elevator("down");

    //Go to next base
    turnLeft(90);
    driveDistance(tileDistance*0.6);
    elevator("up");
    turnRight(45);
    driveDistance(tileDistance*1);
    elevator("down");

    //Trip 1 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Trip 2 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Trip 3 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Trip 4 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turnRight(90);
    driveDistance(tileDistance*1);
    elevator("up");
    turnRight(90);
    driveDistance(tileDistance*1);
    elevator("down");

    //"2" base, trip 1
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //"2" base, trip 2
    turnRight(180);
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //"2" base, trip 3
    turnRight(180);
    driveDistance(tileDistance*0.9);
    elevator("up");
    turnLeft(90);
    driveDistance(tileDistance*0.5);
    flipBar(color);
    turnLeft(135);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Go to the top "3" base and trip 1
    turnLeft(160);
    driveDistance(tileDistance*2.4);
    elevator("up");
    turnLeft(90);
    driveDistance(tileDistance*0.7);
    elevator("down");

    //Top "3" base, trip 2
    turnRight(180);
    driveDistance(tileDistance*1.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Top "3" base, trip 3
    turnRight(180);
    driveDistance(tileDistance*1.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");

    //Top "3" base, trip 4
    turnLeft(90);
    driveDistance(tileDistance*1.0);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance*0.9);
    elevator("down");
}