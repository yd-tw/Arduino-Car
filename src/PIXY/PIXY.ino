#include <Pixy2.h>
#include "PIXY.h"

PIXY pixy;

void setup() {
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  int i=0;
  i = pixy.get();

  int x = pixy.ccc.blocks[i].m_x;
  int y = pixy.ccc.blocks[i].m_y;

  Serial.print("x:");
  Serial.print(x);
  Serial.print(",y:");
  Serial.println(y);

  delay(250);
}