#ifndef ROUTINE_H
#define ROUTINE_H

#include "vex.h"
#include "setup.h"
#include <string>

using namespace std;

void flipBar(string color);

void elevator(string action);

void skillsMode(string color, double tileDistance);

void matchMode(string color, double tileDistance);

void testMode(string color, double tileDistance);

#endif