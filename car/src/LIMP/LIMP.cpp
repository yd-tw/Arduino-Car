#include "LIMP.h"

LIMP::LIMP(int pin) {
  _pin = pin;
}

void LIMP::begin() {
  pinMode(_pin, OUTPUT);
}

void LIMP::on() {
  digitalWrite(_pin, HIGH);
}

void LIMP::off() {
  digitalWrite(_pin, LOW);
}
