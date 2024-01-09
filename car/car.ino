#include <Servo.h>
#include "src/HCSR04/HCSR04.h"
#include "src/L298N/L298N.h"
#include "src/LIGHT/LIGHT.h"

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 11

#define R_TRIG 2
#define R_ECHO A0
#define L_TRIG 4
#define L_ECHO A1

#define SERVO 9
#define LED 13

#define SEE 7
#define GET 8

#define Mode1 10
#define Mode2 12

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);
LIGHT led(LED);
Servo servo;

int see = 0;
int get = 0;
int mode1 = 0;
int mode2 = 0;
int leftDistance = 0;
int rightDistance = 0;

void setup() {
  Serial.begin(9600);
  left.begin();
  right.begin();
  motor.begin();
  led.begin();
  servo.attach(SERVO);
}

void loop() {
  see = digitalRead(SEE);
  get = digitalRead(GET);

  Serial.print("loop, SEE:");
  Serial.print(see);
  Serial.print(" get:");
  Serial.print(get);

  if (see == 1) {
    led.on();
    motor.stop(0);

    if (get == 1) {
      getBall();
    } else {
      revise();
      delay(100);
    }
  } else {
    led.off();
    avoidance();
    delay(100);
  }

  delay(10);
  Serial.println();
}

void avoidance() {
  leftDistance = left.distance();
  rightDistance = right.distance();

  Serial.print("left: ");
  Serial.print(leftDistance);
  Serial.print(", right: ");
  Serial.print(rightDistance);
  Serial.print(" ");

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
  mode1 = digitalRead(Mode1);
  mode2 = digitalRead(Mode2);

  if ((mode1 == 0) && (mode2 == 0)) {
    motor.forward(100);
    Serial.print("small forward, ");
  } else if ((mode1 == 0) && (mode2 == 1)) {
    motor.back(100);
    Serial.print("small back, ");
  } else if ((mode1 == 1) && (mode2 == 0)) {
    motor.left(100);
    Serial.print(",small left, ");
  } else if ((mode1 == 1) && (mode2 == 1)) {
    motor.right(100);
    Serial.print("small right, ");
  }
}

void getBall() {
  Serial.print("getBall, ");
  // servo.write(30);
  // delay(1000);
  // servo.write(100);
  // delay(1000);
  // servo.write(135);
  // delay(1000);
}
