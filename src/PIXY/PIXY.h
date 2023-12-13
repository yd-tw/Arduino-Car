#ifndef PIXY_h
#define PIXY_h

#include "Arduino.h"
#include <Pixy2.h>

class PIXY {
public:
  void init();
  int get();

  Pixy2 ccc;

private:
  int findLargestBlock();
};

#endif