#include <Servo.h>
#include "src/HCSR04/HCSR04.h"
#include "src/L298N/L298N.h"

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 11

#define R_TRIG 2
#define R_ECHO A0
#define L_TRIG 4
#define L_ECHO A1

#define SERVO 9
#define LIGHT 13

#define SEE 7
#define CATCH 8

#define PIN1 10
#define PIN2 12

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);
Servo servo;

int leftDistance = 0;
int rightDistance = 0;

void setup() {
  Serial.begin(9600);
  left.begin();
  right.begin();
  motor.begin();
  servo.attach(SERVO);
}

void loop() {
  Serial.print("loop: ");

  if (digitalRead(SEE)) {
    motor.stop(0);

    if (digitalRead(CATCH)) {
      servo.write(30);
      delay(1000);
      servo.write(100);
      delay(1000);
      servo.write(135);
      delay(1000);
    } else {
      revise()
    }
  } else {
    leftDistance = left.distance();
    rightDistance = right.distance();

    Serial.print(leftDistance);
    Serial.print(",");
    Serial.print(rightDistance);

    avoidance();
  }

  delay(50);
  Serial.println();
}

void avoidance() {
  if ((leftDistance < 25) && (rightDistance < 25)) {
    motor.back(100);
  } else if (leftDistance < 25) {
    motor.right(100);
  } else if (rightDistance < 25) {
    motor.left(100);
  } else {
    motor.forward(100);
  }
}

void revise() {
  int pin1 = digitalRead(PIN1);
  int pin2 = digitalRead(PIN2);

  if ((pin1 == 0) && (pin2 == 0)) {
    motor.forward(100);
  } else if ((pin1 == 0) && (pin2 == 1)) {
    motor.back(100);
  } else if ((pin1 == 1) && (pin2 == 0)) {
    motor.left(100);
  } else if ((pin1 == 1) && (pin2 == 1)){
    motor.right(100);
  }
  delay(100);
}
