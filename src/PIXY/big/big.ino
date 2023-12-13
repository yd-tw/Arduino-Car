#include <Pixy2.h>

Pixy2 pixy;

void setup() {
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  int i;
  i = get();

  int x = pixy.ccc.blocks[i].m_x;
  int y = pixy.ccc.blocks[i].m_y;

  Serial.print("x:");
  Serial.print(x);
  Serial.print(",y:");
  Serial.println(y);

  delay(250);
}

int get() {
  int key = 0;
  int max = 0;
  pixy.ccc.getBlocks();

  if (pixy.ccc.numBlocks) {
    int i;
    for (i = 0; i < pixy.ccc.numBlocks; i++) {
      int a = pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;
      if (max < a) {
        key = i;
        max = a;
      }
    }
  }

  return key;
}
