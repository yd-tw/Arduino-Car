#include <Servo.h>
#include "src/Pixy2/Pixy2.h"
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

#define SERVO 10
#define LIGHT 13

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);
Servo servo;
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
  servo.attach(SERVO);

  delay(10);
}

void loop() {
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks) {
    motor.stop(0);

    i = getKey();
    x = getX(i);
    y = getY(i);

    if (x < 100) {
      servo.write(30);
      delay(1000);
      servo.write(100);
      delay(1000);
      servo.write(135);
      delay(1000);
    }

  } else {
    leftDistance = left.distance();
    rightDistance = right.distance();

    avoidance();
  }

  delay(50);
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

int getX(int i) {
  return pixy.ccc.blocks[i].m_x;
}

int getY(int i) {
  return pixy.ccc.blocks[i].m_y;
}

int getKey() {
  int key = 0;
  int max = 0;

  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    int a = pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;
    if (max < a) {
      key = i;
      max = a;
    }
  }

  return key;
}
