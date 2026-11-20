
#include "mechanical.h"
#include "vex.h"
#include "setup.h"

void pre_auton(void) {

  clawMotor.setStopping(brakeType::hold);
  autoOpenClaw();
  autoCloseClaw();

  liftMotors.setStopping(brakeType::hold);

  //Calibrate Inertial Sensor
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()) {
    wait(100, msec);
  }

}