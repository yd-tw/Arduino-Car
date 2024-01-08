#include "src/Pixy2/Pixy2.h"

#define SEE 2
#define CATCH 3

#define PIN1 8
#define PIN2 9

Pixy2 pixy;

int i;
int x;
int y;

void setup() {
  Serial.begin(9600);
  pinMode(SEE, OUTPUT);
  pinMode(CATCH, OUTPUT);
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pixy.init();
}

void loop() {
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks) {
    digitalWrite(SEE, HIGH);
    i = getKey();
    x = getX(i);
    y = getY(i);

    Serial.print("x:");
    Serial.print(x);
    Serial.print(", y:");
    Serial.print(y);

    if (100 < y) {
      digitalWrite(PIN1, 0);
      digitalWrite(PIN2, 0);
      Serial.print(", Send:right");
    } else if (y < 20) {
      digitalWrite(PIN1, 0);
      digitalWrite(PIN2, 1);
      Serial.print(", Send:left");
    } else {
      if (120 < x) {
        digitalWrite(PIN1, 1);
        digitalWrite(PIN2, 0);
        Serial.print(", Send:forward");
      } else if (x < 80) {
        digitalWrite(PIN1, 1);
        digitalWrite(PIN2, 1);
        Serial.print(", Send:back");
      } else {
        Serial.println("catch");
        digitalWrite(CATCH, HIGH);
        Serial.print(", Send:catch");
      }
    }

  } else {
    digitalWrite(SEE, LOW);
    Serial.println("None");
  }

  delay(50);
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
