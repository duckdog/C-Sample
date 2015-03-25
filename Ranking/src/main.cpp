
#include "System/environment.h"
#include "Ranking/ranking.h"


int main() {
  env::get();

  while (env::get()->isOpen()) {
    env::get()->begin();

    drawFillCircle(0, 0, 50, 50, 100, Color::white);

    env::get()->end();
  }
}
