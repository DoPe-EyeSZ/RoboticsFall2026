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

double updateFilteredCenterX(double measuredCenterX, double &filteredCenterX,
                             bool &filterInitialized) {
  if (!filterInitialized) {
    filteredCenterX = measuredCenterX;
    filterInitialized = true;
  } else {
    filteredCenterX = 0.5 * measuredCenterX + 0.5 * filteredCenterX;
  }
  return filteredCenterX;
}

void Vision(VisionTarget target) {

  const double kP = 0.08;
  const double kD = 0.25;

  //Make sure to update early and update often; signature values are dependent on lighting environment and noise from different sensors
  //Be consistent with the specific vision sensor used
  vision::signature yellowSignature(
      1, 9781, 10387, 10084, -885, -381, -634, 3.0, 0);
  vision::signature redSignature(
      2, -6219, -5499, -5858, 8249, 9423, 8836, 2.5, 0);
  vision::signature blueSignature(
      3, 253, 925, 590, -4237, -3571, -3904, 2.5, 0);
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
  
  VisionSensor.setBrightness(15);
  // Center of the vision sensor's field of view
  const double center = 158.0;
  double lastError = 0;
  bool centered = false;

  double err = 0;
  double last_err = 0;
  double derivative = 0;
  const double tolerance = 5.0;
  const double TurnLimit = 25.0;
  const double ApproachSpeed = 25.0;
  const double SearchSpeed = 15.0;
  const int TargetHeight = 100;
  const int PhaseTimeout = 90000;
  const int LoopDelay = 20;
  const int SearchDirectionInterval = 1000;

  for (int elapsed = 0; elapsed < PhaseTimeout; elapsed += LoopDelay) {
    VisionSensor.takeSnapshot(*selectedSignature);
    if (!VisionSensor.largestObject.exists) {
      lastError = 0;
      const double searchOutput =
          (elapsed / SearchDirectionInterval) % 2 == 0 ? SearchSpeed : -SearchSpeed;
      turnToTarget(searchOutput);
      wait(LoopDelay, msec);
      continue;
    }

    const double error = VisionSensor.largestObject.centerX - center;
    if (error >= -tolerance && error <= tolerance) {
      centered = true;
      stopDrive();
      break;
    }

    double turnOutput = (kP * error) + (kD * (error - lastError));
    if (turnOutput > TurnLimit) {
      turnOutput = TurnLimit;
    } else if (turnOutput < -TurnLimit) {
      turnOutput = -TurnLimit;
    }
    turnToTarget(turnOutput);
    lastError = error;
    wait(LoopDelay, msec);
  }

  if (!centered) {
    stopDrive();
    return;
  }
  lastError = 0;
  for (int elapsed = 0; elapsed < PhaseTimeout; elapsed += LoopDelay) {
    VisionSensor.takeSnapshot(*selectedSignature);
    if (!VisionSensor.largestObject.exists) {
      break;
    }
    if (VisionSensor.largestObject.height >= TargetHeight) {
      break;
    }

    const double error = VisionSensor.largestObject.centerX - center;
    double correction = (kP * error) + (kD * (error - lastError));
    if (correction > TurnLimit) {
      correction = TurnLimit;
    } else if (correction < -TurnLimit) {
      correction = -TurnLimit;
    }

    leftWheels.spin(forward, ApproachSpeed + correction, percent);
    rightWheels.spin(forward, ApproachSpeed - correction, percent);
    lastError = error;
    wait(LoopDelay, msec);
  }

  stopDrive();
  last_err = 0;
  for (int elapsed = 0; elapsed < PhaseTimeout; elapsed += LoopDelay) {
    VisionSensor.takeSnapshot(*selectedSignature);
    if (!VisionSensor.largestObject.exists) {
      break;
    }

    err = VisionSensor.largestObject.centerX - center;
    if (err <= tolerance && err >= -tolerance) {
      break;
    }

    derivative = err - last_err;
    double vel_output = (kP * err) + (kD * derivative);
    if (vel_output > TurnLimit) {
      vel_output = TurnLimit;
    } else if (vel_output < -TurnLimit) {
      vel_output = -TurnLimit;
    }
    turnToTarget(vel_output);
    last_err = err;
    wait(LoopDelay, msec);
  }

  stopDrive();
}