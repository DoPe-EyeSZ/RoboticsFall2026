

#include "vex.h"
#include "setup.h"

const int RIGHT_ANGLE_TURN = 60;

void autonomous() {
  
    //Gets current angle of the rotation sensor's shaft
  double angle = RotationSensor.angle(degrees);
  double position = RotationSensor.position(rotationUnits::deg);

  //This prints the current angle/heading of the shaft
  Brain.Screen.print(angle);
  Brain.Screen.print(position);

  //Rotation sensor PID, linear movement
  //Coefficients still need fine tuning
  double kP = 1.0; //proportional
  double kI = 0.1; //integral
  double kD = 0.05; //derivative

  double err = 0;
  double last_err = 0;
  double tolerance = 1.0;
  double derivative = 0;
  double integral = 0;

    //TODO: USE INERTIAL SENSOR TO GET DATA
    InertialSensor.setHeading(0, rotationUnits::deg); // Reset the head of Inertial Sensor to 0 degrees

    while (InertialSensor.heading() < 90){
        driveTrain.turnFor(right, RIGHT_ANGLE_TURN, deg); // Turn to 90 degrees
    }
    

  

}