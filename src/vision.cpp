#include "vex.h"
#include "setup.h"

//10/9/2026: Main focus is to get robot to detect a colored pin and drive to it smoothly (combining both linear and turning logic)

//Vision sensor/drivetrain integration PID coefficients

void Vision() {

double kP = 0.08;
double kD = 0.25;

//double x.center = VisionSensor.largestObject.centerX;
double err = 0;
double last_err = 0;
double derivative = 0;
double tolerance = 5.0;

while(abs(x.center - center) > tolerance) {
  err = x.center - center;
  derivative = (err - last_err);
  double vel_output = (kP * err) + (kD * derivative);

  leftMotorFront.spin(forward, vel_output, voltageUnits::volt);
  rightMotorFront.spin(forward, vel_output, voltageUnits::volt);

  last_err = err;

  wait(20, msec);
}
}