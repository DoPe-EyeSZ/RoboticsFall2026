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

#endif