
#include "vex.h"
#include "setup.h"

void pre_auton(void) {

  //Calibrate Inertial Sensor
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()) {
    wait(100, msec);
  }

}