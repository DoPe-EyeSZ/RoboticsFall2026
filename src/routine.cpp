#include "vex.h"
#include "inertial.h"
#include "odometry.h"
#include "mechanical.h"
//#include "vision.h" - not being used right now
#include <cmath>
#include <string>
//#include "vision.h" //not being used right now

using namespace std;

namespace {
//Autonomous constants
constexpr double kTripDistanceScale = 0.9;
constexpr double kShortDistanceScale = 0.3;
constexpr double kDriveTimeoutSeconds = 3.0;
constexpr double kBaseTransitionDistanceScale = 0.6;
constexpr double kHalfTileDistanceScale = 0.5;
constexpr double kFullTileDistanceScale = 1.0;
constexpr double kTopBaseApproachDistanceScale = 2.4;
constexpr double kTopBaseOffsetDistanceScale = 0.7;

}

void testMode(string color, double tileDistance) {
    //CHANGE ON MATCH
    //const string color = "red"; 
    //const double tileDistance = 61; //cm

    /*      
    //Trip 1 (stack grey thing on base)
    turnLeft(10);
    //driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    if (color == "yellow") {
        Vision(VisionTarget::yellow);
    } else if (color == "red") {
        Vision(VisionTarget::red);
    } else if (color == "blue") {
        Vision(VisionTarget::blue);
    }
    */
    //Test for odometry functionality
    //driveDistance(-tileDistance/5);
    //turnLeft(45);
    //driveDistance(tileDistance * 1.4);
    //driveDistance(tileDistance);
    //intake("in");
    processPin();
    //driveDistance(-tileDistance*0.5);
    //turnLeft(90);
    //driveDistance(tileDistance*0.9);
    //turnRight(90);
    //driveDistance(tileDistance*1.5);
    
}

//For head-to-head match
//There will be 2 alliance bots on our half of field, so let's restrict this bot's movement to one's of the triangle spaces
void matchMode(string color, double tileDistance){
    //CHANGE ON MATCH
    //const string color = "red"; 
    //const double tileDistance = 61; //cm

    //Flipping bar thing
    turnRight(180);
    flipBar(color);

    //Trip 1 (stack grey thing on base)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("up");
    turnRight(85);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("down");

    //Trip 2 (stack yellow cone on grey thing)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("down");

    //Trip 3 (stack grey thing on yellow)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("down");

    //Trip 4 (stack yellow gone on grey)
    turnLeft(85);
    driveDistance(tileDistance * kShortDistanceScale);
    elevator("up");
    turnRight(160);
    driveDistance(tileDistance * kShortDistanceScale);
    elevator("down");

    //Go to next base
    //Check timing on this run
    turnLeft(90);
    driveDistance(tileDistance * kBaseTransitionDistanceScale);
    elevator("up");
    turnRight(45);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("down");

    //Trip 1 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Trip 2 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Trip 3 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Trip 4 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("up");
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("down");

    //"2" base, trip 1
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //"2" base, trip 2
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //"2" base, trip 3
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(90);
    driveDistance(tileDistance * kHalfTileDistanceScale);
    flipBar(color);
    turnLeft(135);
    driveDistance(+tileDistance * kTripDistanceScale);
    elevator("down");

}

//Skills mode; do half the field 
void skillsMode(string color, double tileDistance){

    //Flipping bar thing
    turnRight(180);
    flipBar(color);

    //Trip 1 (stack grey thing on base)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("up");
    turnRight(85);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("down");

    //Trip 2 (stack yellow cone on grey thing)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("down");

    //Trip 3 (stack grey thing on yellow)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    elevator("down");

    //Trip 4 (stack yellow gone on grey)
    turnLeft(85);
    driveDistance(tileDistance * kShortDistanceScale);
    elevator("up");
    turnRight(160);
    driveDistance(tileDistance * kShortDistanceScale);
    elevator("down");

    //Go to next base
    turnLeft(90);
    driveDistance(tileDistance * kBaseTransitionDistanceScale);
    elevator("up");
    turnRight(45);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("down");

    //Trip 1 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Trip 2 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Trip 3 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Trip 4 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("up");
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("down");

    //"2" base, trip 1
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //"2" base, trip 2
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //"2" base, trip 3
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("up");
    turnLeft(90);
    driveDistance(tileDistance * kHalfTileDistanceScale);
    flipBar(color);
    turnLeft(135);
    driveDistance(+tileDistance * kTripDistanceScale);
    elevator("down");

    //Go to the top "3" base and trip 1
    turnLeft(160);
    driveDistance(tileDistance * kTopBaseApproachDistanceScale);
    elevator("up");
    turnLeft(90);
    driveDistance(tileDistance * kTopBaseOffsetDistanceScale);
    elevator("down");

    //Top "3" base, trip 2
    turnRight(180);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Top "3" base, trip 3
    turnRight(180);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");

    //Top "3" base, trip 4
    turnLeft(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    elevator("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    elevator("down");
}