#include "vex.h"
#include "setup.h"
#include "mechanical.h"

// User control code here, inside the loop
void usercontrol() {
  leftWheels.setStopping(brakeType::coast);
  rightWheels.setStopping(brakeType::coast);
  liftMotors.setStopping(brakeType::hold);
  clawMotor.setStopping(brakeType::hold);

  // Set claw to toggle
  Controller1.ButtonR2.pressed(openClaw);
  Controller1.ButtonL2.pressed(closeClaw);

  // Lift logic
  const int MAX_RPM = 100;
  const double idealSpinPerc = 75;
  const double idealRPM = MAX_RPM * (idealSpinPerc/100);
  double spinPercent = idealSpinPerc;
  double err;

  while (true) {
    //Get speed from controller joysticks
    int forwardSpeed = -Controller1.Axis3.position(); 
    forwardSpeed = (forwardSpeed * forwardSpeed * forwardSpeed) / 10000;

    int sideSpeed = -Controller1.Axis1.position(); 


    //incrase power of lift motors to make it more responsive



    // Control lift motor
    if (Controller1.ButtonB.pressing()) {

      liftUp(spinPercent);

      if (liftMotors.velocity(vex::velocityUnits::rpm) >= 10 ){
        err = idealRPM - liftMotors.velocity(vex::velocityUnits::rpm);
        if (err >= 5){
          spinPercent = idealSpinPerc * (idealRPM / liftMotors.velocity(vex::velocityUnits::rpm));
        }
      }
      

    }
    else if (Controller1.ButtonA.pressing()) {
      liftDown();
      spinPercent = idealSpinPerc;
    } 
    else {
      liftMotors.stop();
      spinPercent = idealSpinPerc;
    }

    leftWheels.spin(vex::directionType::fwd, forwardSpeed + sideSpeed, vex::velocityUnits::pct);
    rightWheels.spin(vex::directionType::fwd, forwardSpeed - sideSpeed, vex::velocityUnits::pct);

    wait(20, vex::msec); // Sleep the task for a short amount of time to
  }
}