

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

    //TODO: USE INERTIAL SENSOR TO GET DATA
    InertialSensor.setHeading(0, rotationUnits::deg); // Reset the head of Inertial Sensor to 0 degrees

    while (InertialSensor.heading() < 90){
        driveTrain.turnFor(right, RIGHT_ANGLE_TURN, deg); // Turn to 90 degrees
    }
    

  

}