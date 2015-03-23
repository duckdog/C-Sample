
#include "Environment/environment.h"


int main() {
  env::manipulator();

  while (env::manipulator().isOpen()) {
    env::manipulator().setupDraw();

    drawPoint(0, 0, 20, Color(1, 1, 1));

    env::manipulator().update();
  }
}
