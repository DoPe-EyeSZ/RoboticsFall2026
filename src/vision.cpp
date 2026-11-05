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

void printVisionStatus(const char *status) {
  Controller1.Screen.clearLine(1);
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Vision: %s", status);
}

void turnToTarget(double output) {
  if (output >= 0) {
    leftWheels.spin(reverse, output, percent);
    rightWheels.spin(forward, output, percent);
  } else {
    leftWheels.spin(forward, -output, percent);
    rightWheels.spin(reverse, -output, percent);
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
      1, -1, 757, 378, -4355, -3417, -3886, 3, 0);
  vision::signature redSignature(
      2, 10381, 11027, 10704, -999, -605, -802, 3, 0);
  vision::signature blueSignature(
      3, -5267, -4531, -4899, 5213, 6587, 5900, 3, 0);
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
  const double tolerance = 8.0;
  const double TurnLimit = 25.0;
  const double MinimumTurnOutput = 5.0;
  const double ApproachSpeed = 25.0;
  const int PhaseTimeout = 90000;
  const int LoopDelay = 20;
  const int RequiredCenteredFrames = 3;
  double initialFilteredCenterX = 0;
  bool initialFilterInitialized = false;
  int initialCenteredFrames = 0;
  bool targetVisible = false;

  //Loop this logic
  printVisionStatus("Searching");
  for (int elapsed = 0; elapsed < PhaseTimeout; elapsed += LoopDelay) {
    VisionSensor.takeSnapshot(*selectedSignature);
    if (!VisionSensor.largestObject.exists) {
      if (targetVisible) {
        printVisionStatus("Searching");
        targetVisible = false;
      }
      lastError = 0;
      initialFilterInitialized = false;
      initialCenteredFrames = 0;
      wait(LoopDelay, msec);
      continue;
    }
    if (!targetVisible) {
      printVisionStatus("Aligning");
      targetVisible = true;
    }

    const double error =
        updateFilteredCenterX(VisionSensor.largestObject.centerX,
                              initialFilteredCenterX,
                              initialFilterInitialized) -
        center;
    if (error >= -tolerance && error <= tolerance) {
      initialCenteredFrames++;
      stopDrive();
      if (initialCenteredFrames >= RequiredCenteredFrames) {
        centered = true;
        break;
      }
    } else {
      initialCenteredFrames = 0;
      double turnOutput = (kP * error) + (kD * (error - lastError));
      if (turnOutput > TurnLimit) {
        turnOutput = TurnLimit;
      } else if (turnOutput < -TurnLimit) {
        turnOutput = -TurnLimit;
      }
      if (turnOutput >= 0 && turnOutput < MinimumTurnOutput) {
        turnOutput = error > 0 ? MinimumTurnOutput : -MinimumTurnOutput;
      } else if (turnOutput < 0 && turnOutput > -MinimumTurnOutput) {
        turnOutput = -MinimumTurnOutput;
      }
      turnToTarget(turnOutput);
    }
    lastError = error;
    wait(LoopDelay, msec);
  }

  if (!centered) {
    stopDrive();
    return;
  }
  lastError = 0;
  double approachFilteredCenterX = 0;
  bool approachFilterInitialized = false;
  while (true) {
    VisionSensor.takeSnapshot(*selectedSignature);
    if (!VisionSensor.largestObject.exists) {
      stopDrive();
      return;
    }

    const double error =
        updateFilteredCenterX(VisionSensor.largestObject.centerX,
                              approachFilteredCenterX,
                              approachFilterInitialized) -
        center;
    double correction = (kP * error) + (kD * (error - lastError));
    if (correction > TurnLimit) {
      correction = TurnLimit;
    } else if (correction < -TurnLimit) {
      correction = -TurnLimit;
    }
    if (error > tolerance && correction < MinimumTurnOutput) {
      correction = MinimumTurnOutput;
    } else if (error < -tolerance && correction > -MinimumTurnOutput) {
      correction = -MinimumTurnOutput;
    }

    leftWheels.spin(reverse, ApproachSpeed - correction, percent);
    rightWheels.spin(reverse, ApproachSpeed + correction, percent);
    lastError = error;
    wait(LoopDelay, msec);
  }

  stopDrive();
}