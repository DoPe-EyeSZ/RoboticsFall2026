#ifndef MECHANICAL_H
#define MECHANICAL_H

#include "vex.h"
#include "setup.h"
#include <string>

using namespace std;

void flipBar(string color);

void lift(string action, double maxTime = 3);

void autoCloseClaw();

void autoOpenClaw();

void processPin();

// Functions for MANUAL CONTROL ONLY
void openClaw();

void closeClaw();

void liftUp(double spinPercent);

void liftDown();

#endif