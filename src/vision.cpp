#include "vex.h"
//#include "robot-config.h"
#include "setup.h"
#include "vision.h"

//10/9/2026: Main focus is to get robot to detect a colored pin and drive to it smoothly (combining both linear and turning logic)

//Vision sensor/drivetrain integration PID coefficients

void stopDrive() {
  leftWheels.stop();
  rightWheels.stop();
}

void turnToTarget(double output) {
  if (output >= 0) {
    leftWheels.spin(forward, output, percent);
    rightWheels.spin(reverse, output, percent);
  } else {
    leftWheels.spin(reverse, -output, percent);
    rightWheels.spin(forward, -output, percent);
  }
}

void Vision(VisionTarget target) {

  const double kP = 0.08;
  const double kD = 0.25;

  vision::signature yellowSignature(
      1, 2717, 3085, 2901, -4739, -4443, -4591, 2.5, 0);
  vision::signature redSignature(
      2, 11929, 13041, 12485, -1809, -1433, -1621, 2.5, 0);
  vision::signature blueSignature(
      3, -4275, -3261, -3768, 2315, 3429, 2872, 2.5, 0);
  vision::signature *selectedSignature = 0;

  switch (target) {
    case VisionTarget::yellow:
      selectedSignature = &yellowSignature;
      break;
    case VisionTarget::red:
      selectedSignature = &redSignature;
      break;
    case VisionTarget::blue:
      selectedSignature = &blueSignature;
      break;
    default:
      stopDrive();
      return;
  }

  VisionSensor.setBrightness(29);
  // Center of the vision sensor's field of view
  const double center = 158.0;
  double lastError = 0;
  bool centered = false;
  }

  double err = 0;
  double last_err = 0;
  double derivative = 0;
  const double tolerance = 5.0;
  const double TurnLimit = 25.0;
  const double ApproachSpeed = 25.0;
  const int TargetHeight = 100;
  const int PhaseTimeout = 5000;
  const int LoopDelay = 20;

  for (int elapsed = 0; elapsed < PhaseTimeout; elapsed += LoopDelay) {
    VisionSensor.takeSnapshot(*selectedSignature);
    if (!VisionSensor.largestObject.exists) {
      stopDrive();
      wait(LoopDelay, msec);
      continue;
    }

  while(abs(VisionSensor.largestObject.centerX - center) > tolerance) {
    err = VisionSensor.largestObject.centerX - center;
    derivative = (err - last_err);
    double vel_output = (kP * err) + (kD * derivative);

    leftWheels.spin(forward, vel_output, percent);
    rightWheels.spin(reverse, vel_output, percent);

    last_err = err;

    wait(20, msec);
  }
}