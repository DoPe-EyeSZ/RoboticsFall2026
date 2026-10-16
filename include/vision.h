#ifndef VISION_H
#define VISION_H

#include "vex.h"
#include "setup.h"

enum class VisionTarget {
  yellow,
  red,
  blue
};

void Vision(VisionTarget target = VisionTarget::yellow);

#endif