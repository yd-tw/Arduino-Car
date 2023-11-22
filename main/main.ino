#include "HCSR04.h"
#include "L298N.h"

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 11

#define L_TRIG 2
#define L_ECHO A0
#define R_TRIG 4
#define R_ECHO A1

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);

void setup()
{
  Serial.begin(9600);
  left.begin();
  right.begin();
  motor.begin();

  delay(100);
}

void loop()
{
  int leftDistance = left.distance();
  int rightDistance = right.distance();

  delay(25);

  if (leftDistance < 25 && right.distance() < 25) {
    motor.back(80);
  }
  else if (leftDistance < 25) {
    motor.right(80);
  }
  else if (right.distance() < 25) {
    motor.left(80);
  }
  else {
    motor.forward(80);
  }
}
