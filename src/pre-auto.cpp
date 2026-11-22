
#include "mechanical.h"
#include "vex.h"
#include "setup.h"

void pre_auton(void) {

  clawMotor.setStopping(brakeType::hold);
  liftMotors.setStopping(brakeType::hold);
  autoOpenClaw();
  clawMotor.stop();


  //Calibrate Inertial Sensor
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()) {
    wait(100, msec);
  }

}