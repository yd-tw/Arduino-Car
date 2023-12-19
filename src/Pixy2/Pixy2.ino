#include "Pixy2.h"

Pixy2 pixy;

int i;
int x;
int y;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pixy.init();
}
void loop() {
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks) {
    i = getKey();
    x = getX(i);
    y = getY(i);

    Serial.print("x:");
    Serial.print(x);
    Serial.print(",y:");
    Serial.println(y);

    if ((80 < x) && (x < 120)) {
      Serial.println("catch");
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(3, LOW);
    }

  } else {
    Serial.println("None");
  }

  delay(100);
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

  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    int a = pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;
    if (max < a) {
      key = i;
      max = a;
    }
  }

  return key;
}
