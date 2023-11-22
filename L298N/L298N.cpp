#include "L298N.h"

L298N::L298N(int in1, int in2, int in3, int in4) {
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
}

void L298N::begin() {
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
}

void L298N::forward(int speed)
{
  analogWrite(_in1, speed);
  analogWrite(_in2, 0);
  analogWrite(_in3, 0);
  analogWrite(_in4, speed);
}

void L298N::back(int speed)
{
  analogWrite(_in1, 0);
  analogWrite(_in2, speed);
  analogWrite(_in3, speed);
  analogWrite(_in4, 0);
}

void L298N::left(int speed)
{
  analogWrite(_in1, 0);
  analogWrite(_in2, 0);
  analogWrite(_in3, 0);
  analogWrite(_in4, speed);
}

void L298N::right(int speed)
{
  analogWrite(_in1, speed);
  analogWrite(_in2, 0);
  analogWrite(_in3, 0);
  analogWrite(_in4, 0);
}

void L298N::stop(int speed)
{
  analogWrite(_in1, 0);
  analogWrite(_in2, 0);
  analogWrite(_in3, 0);
  analogWrite(_in4, 0);
}
