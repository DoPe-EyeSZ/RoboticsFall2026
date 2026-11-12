#include "vex.h"
//#include "setup.h" - not being used right now
#include "inertial.h"
#include "odometry.h"
//#include "vision.h" - not being used right now
#include "mechanical.h"
#include <cmath>
#include <string>
#include "vision.h"

using namespace std;

namespace {
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

    turnRight(180);
    turnLeft(180);
    turnRight(90);
    turnLeft(90);
    
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
    lift("up");
    turnRight(85);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 2 (stack yellow cone on grey thing)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 3 (stack grey thing on yellow)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 4 (stack yellow gone on grey)
    turnLeft(85);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("up");
    turnRight(160);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("down");

    //Go to next base
    //Check timing on this run
    turnLeft(90);
    driveDistance(tileDistance * kBaseTransitionDistanceScale);
    lift("up");
    turnRight(45);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //Trip 1 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 2 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 3 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 4 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //"2" base, trip 1
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 2
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 3
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(90);
    driveDistance(tileDistance * kHalfTileDistanceScale);
    flipBar(color);
    turnLeft(135);
    driveDistance(+tileDistance * kTripDistanceScale);
    lift("down");

}

//Skills mode; do half the field 
void skillsMode(string color, double tileDistance){

    //Flipping bar thing
    turnRight(180);
    flipBar(color);

    //Trip 1 (stack grey thing on base)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turnRight(85);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 2 (stack yellow cone on grey thing)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 3 (stack grey thing on yellow)
    turnLeft(175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 4 (stack yellow gone on grey)
    turnLeft(85);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("up");
    turnRight(160);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("down");

    //Go to next base
    turnLeft(90);
    driveDistance(tileDistance * kBaseTransitionDistanceScale);
    lift("up");
    turnRight(45);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //Trip 1 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 2 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 3 (stack gray thing)
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 4 (stack gray thing)
    turnRight(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turnRight(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //"2" base, trip 1
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 2
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 3
    turnRight(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turnLeft(90);
    driveDistance(tileDistance * kHalfTileDistanceScale);
    flipBar(color);
    turnLeft(135);
    driveDistance(+tileDistance * kTripDistanceScale);
    lift("down");

    //Go to the top "3" base and trip 1
    turnLeft(160);
    driveDistance(tileDistance * kTopBaseApproachDistanceScale);
    lift("up");
    turnLeft(90);
    driveDistance(tileDistance * kTopBaseOffsetDistanceScale);
    lift("down");

    //Top "3" base, trip 2
    turnRight(180);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Top "3" base, trip 3
    turnRight(180);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Top "3" base, trip 4
    turnLeft(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turnLeft(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");
}