#ifndef MECHANICAL_H
#define MECHANICAL_H

#include "vex.h"
#include "setup.h"
#include <string>

using namespace std;

void flipBar(string color);

void elevator(string action);

void intake(string direction);

void processPin();

#endif