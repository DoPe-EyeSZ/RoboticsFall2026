#ifndef MECHANICAL_H
#define MECHANICAL_H

#include "vex.h"
#include "setup.h"
#include <string>

using namespace std;

void flipBar(string color);

void lift(string action);

void claw(string direction);

void processPin();

// Functions for auton
void openClaw();

void closeClaw();

void liftUp(double spinPercent);

void liftDown(double spinPercent);

#endif