#include <MsTimer2.h>
#include "Mouse.h"

void uro2mouse() {
  int i, x = 0, y = 0;
  i = random(0, 3);
  switch (i) {
    case 0:
      y = 5;
      break;
    case 1:
      x = 5;
      break;
    case 2:
      y = -5;
      break;
    case 3:
      x = -5;
  }
  Mouse.move(x, y, 0);
}

void setup() {
  randomSeed(analogRead(0));
  Mouse.begin();
  MsTimer2::set(100, uro2mouse);
  MsTimer2::start();
}

void loop() {
}

