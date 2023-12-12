#include <Servo.h>
#include "HCSR04/HCSR04.h"
#include "L298N/L298N.h"

#define GAP 25
#define SPEED 80

#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8

#define R_TRIG 13
#define R_ECHO 12
#define L_TRIG 4
#define L_ECHO 3

#define S_MOTOR 0

Servo armServo;
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

  if ((leftDistance < GAP) && (right.distance() < GAP)) {
    motor.back(SPEED);
  }
  else if (leftDistance < GAP) {
    motor.right(SPEED);
  }
  else if (right.distance() < GAP) {
    motor.left(SPEED);
  }
  else {
    motor.forward(SPEED);
  }
}
