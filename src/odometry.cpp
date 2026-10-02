#include "vex.h"
#include "setup.h"

using namespace vex;
void driveDistance(double targetDistance, double maxTime = 5.0) {
  
  //Wheel configs
  const double wheelCircumference = 15.96; // centimeters
  RotationSensor.setPosition(0, deg);                  

  //gets num of rotations to reach target
  double wheelRotations = targetDistance / wheelCircumference;
  
  //Gets target angle
  double initialAngle = RotationSensor.position(deg);
  double finalAngle = initialAngle + (wheelRotations * 360);

  //Will come back to this for debugging experiments
  //Will come back to this for debugging experiments
  Controller1.Screen.print(initialAngle);
  Controller1.Screen.print(finalAngle);
  Controller1.Screen.newLine();
  Controller1.Screen.print(RotationSensor.position(rotationUnits::deg));
  Controller1.Screen.newLine();
  Controller1.Screen.print(wheelRotations);

  

  //Rotation sensor PID, linear movement
  double kP = 0.1; 
  double kD = 0.0; 

  double err;
  double prev_err = finalAngle - RotationSensor.position(deg);

  double derivative;
  double motorPow;

  timer t;
  t.reset();

  while (t.time(sec) < maxTime) {

    err = finalAngle - RotationSensor.position(deg);;
    if (fabs(err) < 3) break;   // check if the error is within a threshold to break the loop

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
