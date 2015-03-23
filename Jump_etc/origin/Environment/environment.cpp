
#include "environment.h"


env::cEnvironment() :
env_(WIDTH, HEIGHT, false, false) {
}


env env::manipulator() {
  static env env;
  return env;
}


bool env::isLeftClick() {
  return env_.isPushButton(Mouse::LEFT);
}


bool env::isOpen() {
  return env_.isOpen();
}


void env::setupDraw() {
  env_.setupDraw();
}


void env::update() {
  env_.update();
}
