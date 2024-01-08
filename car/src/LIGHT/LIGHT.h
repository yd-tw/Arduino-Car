#ifndef LIGHT_h
#define LIGHT_h

#include "Arduino.h"

class LIGHT {
  public:
    LIGHT(int pin);
    void begin();
    void on();
    void off();

  private:
    int _pin;
};

#endif
