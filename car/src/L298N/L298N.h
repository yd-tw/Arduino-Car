#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N {
  public:
    L298N(int in1, int in2, int in3, int in4);
    void begin();
    void forward(int speed);
    void back(int speed);
    void left(int speed);
    void right(int speed);
    void stop(int speed);
    void set(int leftSpeed, int rightSpeed);

  private:
    int _in1;
    int _in2;
    int _in3;
    int _in4;
};

#endif
