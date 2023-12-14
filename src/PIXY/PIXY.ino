#include <Pixy2.h>

Pixy2 pixy;

void setup() {
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  int i = get();

  int x = getx(i);
  int y = gety(i);

  Serial.print("x:");
  Serial.print(x);
  Serial.print(",y:");
  Serial.println(y);

  delay(250);
}

int getX(int i) {
  return pixy.ccc.blocks[i].m_x;
}
int getY(int i) {
  return pixy.ccc.blocks[i].m_y;
}

int getKey() {
  int key = 0;
  int max = 0;
  pixy.ccc.getBlocks();

  if (pixy.ccc.numBlocks) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      int a = pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;
      if (max < a) {
        key = i;
        max = a;
      }
    }
  }
  
  return key;
}
