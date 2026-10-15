#include "vex.h"
#include "setup.h"

//10/9/2026: Main focus is to get robot to detect a colored pin and drive to it smoothly (combining both linear and turning logic)

//Vision sensor/drivetrain integration PID coefficients

void Vision() {

  double kP = 0.15;
  double kD = 0.08;
  
  vision::signature SIG_1 = vision::signature(1, 2717, 3085, 2901, -4739, -4443, -4591, 2.5, 0);
  VisionSensor.setBrightness(29);

  // Center of the vision sensor's field of view 
  double center = 158;    

  double err = 0;
  double last_err = 0;
  double derivative = 0;
  double tolerance = 5.0;

  while(abs(VisionSensor.largestObject.centerX - center) > tolerance) {

    VisionSensor.takeSnapshot(SIG_1);

    if (VisionSensor.largestObject.exists) {
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("Object Detected");
    }

    err = VisionSensor.largestObject.centerX - center;
    derivative = (err - last_err);
    double vel_output = (kP * err) + (kD * derivative);

    leftWheels.spin(forward, vel_output, percent);
    rightWheels.spin(reverse, vel_output, percent);

    last_err = err;

    wait(20, msec);
  }
}