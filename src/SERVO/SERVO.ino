#include <Servo.h>

Servo Servo;

void setup() {
  Servo.attach(10);
}

void loop() {   
  Servo.write(30);
  delay(1000);
  Servo.write(100);
  delay(1000);
  Servo.write(135);
  delay(1000);
}
