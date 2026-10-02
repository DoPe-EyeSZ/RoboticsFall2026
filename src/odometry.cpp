#include "vex.h"
#include "setup.h"

using namespace vex;
void driveDistance(double targetDistance, double maxTime = 5.0) {
  
  //Wheel configs
  const double wheelCircumference = 15.96; // centimeters
  const double kP = 0.95; 
  const double kD = 0.0; 
  RotationSensor.setPosition(0, deg);
  

  //Will come back to this for debugging experiments
  Controller1.Screen.newLine();
  Controller1.Screen.print(RotationSensor.position(rotationUnits::deg));
  Controller1.Screen.newLine();
  Controller1.Screen.print(targetDistance);
  

  double distanceTraveled = (RotationSensor.position(deg) / 360.0) * wheelCircumference;
  double err;
  double prev_err = targetDistance - distanceTraveled;

  double derivative;
  double motorPow;

  timer t;
  t.reset();

  while (t.time(sec) < maxTime) {

    distanceTraveled = (RotationSensor.position(deg) / 360.0) * wheelCircumference;

    err = targetDistance - distanceTraveled;

    if (fabs(err) < 1) break;   // check if the error is within a threshold to break the loop

    derivative = (err - prev_err);

    motorPow = (kP * err) + (kD * derivative);

    //Motor power cap
    if (motorPow > 100.0) motorPow = 100.0;
    if (motorPow < -100.0) motorPow = -100.0;

    leftWheels.spin(forward, motorPow, percent);
    rightWheels.spin(forward, motorPow, percent);

    prev_err = err;

    wait(20, msec);
  }

  leftWheels.stop(brakeType::hold);
  rightWheels.stop(brakeType::hold);
}
