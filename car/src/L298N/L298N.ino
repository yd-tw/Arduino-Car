#include "L298N.h"

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 11

L298N motor(IN1, IN2, IN3, IN4);

void setup()
{
  Serial.begin(9600);
  motor.begin();
}

void loop() {
  motor.forward(100);
  delay(1000);
  motor.back(100);
  delay(1000);
  motor.left(100);
  delay(1000);
  motor.right(100);
  delay(1000);
  motor.stop(100);
  delay(1000);
}
