#include "vex.h"
//#include "setup.h" - not being used right now
#include "inertial.h"
#include "odometry.h"
//#include "vision.h" - not being used right now
#include "mechanical.h"
#include <cmath>
#include <string>
//#include "vision.h" - not being used right now

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

void testMode(string teamColor, double tileDistance) {
    //CHANGE ON MATCH

    //turn(-90);
    //turn(90);
    //driveDistance(tileDistance * 2, kDriveTimeoutSeconds);
    //flipBar("red");
    lift("up");
    
}

//For head-to-head match
//There will be 2 alliance bots on our half of field, so let's restrict this bot's movement to one's of the triangle spaces
void matchMode(string teamColor, double tileDistance){
    //CHANGE ON MATCH
    //const string color = "red"; 
    //const double tileDistance = 61; //cm

    //Flipping bar thing
    turn(180);
    flipBar(teamColor);

    //Trip 1 (stack grey thing on base)
    turn(90);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turn(85);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 2 (stack yellow cone on grey thing)
    turn(-175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 3 (stack grey thing on yellow)
    turn(-175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 4 (stack yellow gone on grey)
    turn(-85);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("up");
    turn(160);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("down");

    //Go to next base
    //Check timing on this run
    turn(-90);
    driveDistance(tileDistance * kBaseTransitionDistanceScale);
    lift("up");
    turn(45);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //Trip 1 (stack gray thing)
    turn(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 2 (stack gray thing)
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 3 (stack gray thing)
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 4 (stack gray thing)
    turn(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turn(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turn(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //"2" base, trip 1
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 2
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 3
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-90);
    driveDistance(tileDistance * kHalfTileDistanceScale);
    flipBar(teamColor);
    turn(-135);
    driveDistance(+tileDistance * kTripDistanceScale);
    lift("down");

}

//Half the 
void skillsMode(string teamColor, double tileDistance){

    //Flipping bar thing
    turn(180);
    flipBar(teamColor);

    //Trip 1 (stack grey thing on base)
    turn(90);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turn(85);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 2 (stack yellow cone on grey thing)
    turn(-175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 3 (stack grey thing on yellow)
    turn(-175);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale, kDriveTimeoutSeconds);
    lift("down");

    //Trip 4 (stack yellow gone on grey)
    turn(-85);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("up");
    turn(160);
    driveDistance(tileDistance * kShortDistanceScale);
    lift("down");

    //Go to next base
    turn(-90);
    driveDistance(tileDistance * kBaseTransitionDistanceScale);
    lift("up");
    turn(45);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //Trip 1 (stack gray thing)
    turn(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 2 (stack gray thing)
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 3 (stack gray thing)
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Trip 4 (stack gray thing)
    turn(90);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Go to the "2" base (up 1 tile, right 1 tile)
    turn(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turn(90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("down");

    //"2" base, trip 1
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 2
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //"2" base, trip 3
    turn(180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("up");
    turn(-90);
    driveDistance(tileDistance * kHalfTileDistanceScale);
    flipBar(teamColor);
    turn(-135);
    driveDistance(+tileDistance * kTripDistanceScale);
    lift("down");

    //Go to the top "3" base and trip 1
    turn(-160);
    driveDistance(tileDistance * kTopBaseApproachDistanceScale);
    lift("up");
    turn(-90);
    driveDistance(tileDistance * kTopBaseOffsetDistanceScale);
    lift("down");

    //Top "3" base, trip 2
    turn(180);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Top "3" base, trip 3
    turn(180);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");

    //Top "3" base, trip 4
    turn(-90);
    driveDistance(tileDistance * kFullTileDistanceScale);
    lift("up");
    turn(-180);
    driveDistance(tileDistance * kTripDistanceScale);
    lift("down");
}