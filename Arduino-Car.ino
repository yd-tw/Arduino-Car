#include <Servo.h>
#include <Pixy2.h>
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

#define A_Servo 10

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);
Servo Servo;
Pixy2 pixy;

int leftDistance = 0;
int rightDistance = 0;
int i = 0;
int x = 0;
int y = 0;

void setup() {
  Serial.begin(9600);
  left.begin();
  right.begin();
  motor.begin();
  pixy.init();
  Servo.attach(A_Servo);

  delay(10);
}

void loop() {
  leftDistance = left.distance();
  rightDistance = right.distance();
  i = get();
  x = getx(i);
  y = gety(i);

  avoidance();

  delay(25);
}

void avoidance() {
  if ((leftDistance < 25) && (right.distance() < 25)) {
    motor.back(100);
  }
  else if (leftDistance < 25) {
    motor.right(100);
  }
  else if (right.distance() < 25) {
    motor.left(100);
  }
  else {
    motor.forward(100);
  }
}

int getX(int i) {
  return pixy.ccc.blocks[i].m_x;
}

int getY(int i) {
  return pixy.ccc.blocks[i].m_y;
}

int getKey() {
  int key = 0;
  int max = 0;
  pixy.ccc.getBlocks();

  if (pixy.ccc.numBlocks) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      int a = pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;
      if (max < a) {
        key = i;
        max = a;
      }
    }
  }

  return key;
}
