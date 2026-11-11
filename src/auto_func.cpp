#include "vex.h"
#include "setup.h"
#include "auto_func.h"
#include <cmath>

int const DEGREE_4_CLOSED_CLAW = 0;     //-------------FIND THIS-----------
int const DEGREE_4_OPEN_CLAW = 90;     //-------------FIND THIS-----------
int const MAX_INTAKE_TIME = 5;


/*
things to fix for "closeClaw" and "liftClaw":
- change ">" if the banshee claw moving down is actually increasing position
- change "bansheeMotor.spin(reverse, 50, percent);" speed from 50 to 100 once testing is good
*/


// Close claw; Boolean tells use whether claw is closed for intake
bool closeClaw(){
    bansheeMotor.spin(reverse, 50, percent);        

    while (bansheeMotor.position(vex::rotationUnits::deg) > DEGREE_4_CLOSED_CLAW){
        wait(10, msec);        
    }

    bansheeMotor.stop(brake);
    return true;

}

// Open claw
void liftClaw(){
    bansheeMotor.spin(forward, 50, percent);        

    while (bansheeMotor.position(vex::rotationUnits::deg) < DEGREE_4_OPEN_CLAW){
        wait(10, msec);        
    }

    bansheeMotor.stop(hold);

}



/*
things to fix:
- might need to change spin direction to reverse
*/
// Runs intake motor to get cone
void getCone(){
    
    if(closeClaw()){
        timer t;
        t.reset();
        intakeMotors.spin(forward, 50, percent);

        while (t.time(sec) < MAX_INTAKE_TIME) {
            wait(10, msec);  
        }

        intakeMotors.stop(hold);


    }
}