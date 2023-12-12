#include <Servo.h>
#include "src/HCSR04/HCSR04.h"
#include "src/L298N/L298N.h"

#define GAP 25
#define SPEED 100

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

#define R_TRIG 2
#define R_ECHO A0
#define L_TRIG 4
#define L_ECHO A1

#define P_Servo 10

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);
Servo Servo;

int leftDistance = 0;
int rightDistance = 0;

void setup() {
  Serial.begin(9600);
  left.begin();
  right.begin();
  motor.begin();
  Servo.attach(10);

  delay(100);
}

void loop() {
  leftDistance = left.distance();
  rightDistance = right.distance();

  if ((leftDistance < GAP) && (right.distance() < GAP)) {
    motor.back(SPEED);
  } else if (leftDistance < GAP) {
    motor.right(SPEED);
  } else if (right.distance() < GAP) {
    motor.left(SPEED);
  } else {
    motor.forward(SPEED);
  }

  delay(25);
}
