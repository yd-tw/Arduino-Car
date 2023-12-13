#include "Pixy2.h"
#include "PIXY.h"

void PIXY::init() {
  ccc.init();
}

int PIXY::get() {
  int key = findLargestBlock();
  return key;
}

int PIXY::findLargestBlock() {
  int key = 0;
  int max = 0;
  ccc.getBlocks();

  if (ccc.numBlocks) {
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