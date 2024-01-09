#include "LIGHT.h"
LIGHT red(13);

void setup()
{
  red.begin();
}


void loop()
{
  red.on();
  delay(100);
  red.off();
  delay(100);
}
