#include "vex.h"
#include "setup.h"

using namespace vex;
void autonomousOdometry(double targetDistance) {
  
  //Wheel configs
  const double wheelCircumference = 25.95; // centimeters
  RotationSensor.setPosition(0, rotationUnits::deg);                    //put in autocpp???:

  //gets num of rotations to reach target
  double wheelRotations = targetDistance / wheelCircumference;
  
  //Gets target angle
  double initialAngle = RotationSensor.position(rotationUnits::deg);
  double finalAngle = initialAngle + (wheelRotations * 360);

  /*
  Controller1.Screen.print(initialAngle);
  Controller1.Screen.print(finalAngle);
  Controller1.Screen.newLine();
  Controller1.Screen.print(RotationSensor.position(rotationUnits::deg));
  Controller1.Screen.newLine();
  Controller1.Screen.print(wheelRotations);
  */
  

  //Rotation sensor PID, linear movement
  double kP = 0.08; 
  double kD = 0.25; 

  double err = 0;
  double prev_err = 0;

  double derivative;
  double motorPow;
  double currAngle;

  int loopDelay = 20; //in milliseconds
  int timeElapsed = 0; //in milliseconds
  int timeRun = 5000; //in milliseconds

  while (timeElapsed < timeRun) {
    currAngle = RotationSensor.position(rotationUnits::deg);

    err = finalAngle - currAngle;
    derivative = (err - prev_err);

    motorPow = (kP * err) + (kD * derivative);

    leftMotorFront.spin(forward, motorPow, percent);
    rightMotorFront.spin(forward, motorPow, percent);

    prev_err = err;

    //Fixed time
    wait(loopDelay, msec);
    timeElapsed += loopDelay;
  }

  leftMotorFront.stop(brakeType::hold);
  rightMotorFront.stop(brakeType::hold);
}
