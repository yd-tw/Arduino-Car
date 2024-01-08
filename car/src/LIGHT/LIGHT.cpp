#include "LIGHT.h"

LIGHT::LIGHT(int pin) {
  _pin = pin;
}

void LIGHT::begin() {
  pinMode(_pin, OUTPUT);
}

void LIGHT::on() {
  digitalWrite(_pin, HIGH);
}

void LIGHT::off() {
  digitalWrite(_pin, LOW);
}
