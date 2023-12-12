#include <Servo.h>

Servo switchServo;
Servo armServo;

void setup() {
  switchServo.attach(9);
  armServo.attach(10);
}

void loop() {   
  switchServo.write(150);
  delay(1000);
  switchServo.write(90);
  delay(1000);
}
