#include "LIMP.h"

LIMP red(13);

void setup()
{
  red.begin();
}


void loop()
{
  red.on();
  delay(50);
  red.off();
  delay(50);
}
