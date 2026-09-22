#include "vex.h"
#include "setup.h"

using namespace vex;
void autonomousOdometry() {
  
  //Wheel configs
  double wheelCircumference = 25.95; //in cm
  double wheeltarget_distance = 50; //in cm

  double wheelRotations = wheeltarget_distance / wheelCircumference; //for how many rotations needed

  RotationSensor.setPosition(0, rotationUnits::deg);
  //Gets current angle of the rotation sensor's shaft
  double initialAngle = RotationSensor.position(rotationUnits::deg);
  double finalAngle = initialAngle + (wheelRotations * 360); //360 degrees for a full rotation

  //This prints the current angle/heading of the shaft
  Controller1.Screen.print(initialAngle);
  Controller1.Screen.print(finalAngle);
  Controller1.Screen.newLine();
  Controller1.Screen.print(RotationSensor.position(rotationUnits::deg));
  Controller1.Screen.newLine();
  Controller1.Screen.print(wheelRotations);

  //Rotation sensor PID, linear movement
  //Coefficients still need fine tuning
  double kP = 0.05; //proportional
  //double kI = 0.1; //integral, not needed
  double kD = 0.25; //derivative

  double err = 0;
  double last_err = 0;
  //double tolerance = 1.0; //not being used right now
  double derivative = 0;
  //double integral = 0; //not being used right now

  RotationSensor.setPosition(0, rotationUnits::deg);


  //New math, new while loop

  int loopDelay = 20; //in milliseconds
  int timeElapsed = 0; //in milliseconds
  int timeRun = 5000; //in milliseconds

  while (timeElapsed < timeRun) {
    double currentAngle = RotationSensor.position(rotationUnits::deg);
    err = finalAngle - currentAngle;

    derivative = (err - last_err);
    double output = (kP * err) + (kD * derivative);

    leftMotorFront.spin(forward, output, voltageUnits::volt);
    rightMotorFront.spin(forward, output, voltageUnits::volt);

    last_err = err;

    //Fixed time
    wait(loopDelay, msec);
    timeElapsed += loopDelay;
  }

  leftMotorFront.stop(brakeType::hold);
  rightMotorFront.stop(brakeType::hold);
}