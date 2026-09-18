

#include "vex.h"
#include "setup.h"

const int RIGHT_ANGLE_TURN = 60;

void autonomous() {
  
  //Wheel configs
  wheelCircumference = 25.95; //in cm
  wheeltarget_distance = 30;  //in cm

  double wheelRotations = wheeltarget_distance / wheelCircumference; //for how many rotations needed

  RotationSensor.setPosition(0, rotationUnits::deg);
  //Gets current angle of the rotation sensor's shaft
  double angle = RotationSensor.angle(degrees);
  double position = RotationSensor.position(rotationUnits::deg);

  //This prints the current angle/heading of the shaft
  Brain.Screen.print(angle);
  Brain.Screen.print(position);

  //Rotation sensor PID, linear movement
  //Coefficients still need fine tuning
  double kP = 0.05; //proportional
  //double kI = 0.1; //integral, not needed
  double kD = 0.25; //derivative

  double err = 0;
  double last_err = 0;
  double tolerance = 1.0;
  double derivative = 0;
  double integral = 0;

  RotationSensor.setPosition(0, rotationUnits::deg);


  //Still need to correct this math and figure out how to send this data to the drivetrain
  while (true) {
    err = 90 - RotationSensor.position(rotationUnits::deg); //Target angle is 90 degrees
    integral += err;
    derivative = err - last_err;
    double output = (kP * err) + (kD * derivative);

    leftMotorFront.spin(forward, output, voltageUnits::volt);
    rightMotorFront.spin(forward, output, voltageUnits::volt);

    last_err = err;
  }

    //TODO: USE INERTIAL SENSOR TO GET DATA
    InertialSensor.setHeading(0, rotationUnits::deg); // Reset the head of Inertial Sensor to 0 degrees

    while (InertialSensor.heading() < 90){
        driveTrain.turnFor(right, RIGHT_ANGLE_TURN, deg); // Turn to 90 degrees
    }
    

  

}