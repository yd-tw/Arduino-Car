#include "HCSR04.h"

HCSR04 left(2, A0);
HCSR04 right(4, A1);

void setup() {
  Serial.begin(9600);
  left.begin();
  right.begin();
}

void loop() {
  Serial.print("left:");
  Serial.print(left.distance());
  Serial.print(" right:");
  Serial.println(right.distance());

  delay(200);
}
