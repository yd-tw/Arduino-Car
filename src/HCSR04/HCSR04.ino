#include "HCSR04.h"

#define R_TRIG 2
#define R_ECHO A0
#define L_TRIG 4
#define L_ECHO A1

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);

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
