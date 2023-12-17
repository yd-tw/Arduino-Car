#include "LIMP.h"

LIMP red(13);

void setup()
{
  red.begin();
}


void loop()
{
  red.on();
  delay(1000);
  red.off();
  delay(1000);
}
