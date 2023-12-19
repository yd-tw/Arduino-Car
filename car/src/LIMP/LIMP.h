#ifndef LIMP_h
#define LIMP_h

#include "Arduino.h"

class LIMP {
  public:
    LIMP(int pin);
    void begin();
    void on();
    void off();

  private:
    int _pin;
};

#endif
