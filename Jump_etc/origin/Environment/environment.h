
#pragma once
#include "../common.h"


class cEnvironment {
  AppEnv env_;

public:
  cEnvironment();

  static cEnvironment manipulator();

  bool isLeftClick();

  bool isOpen();

  void setupDraw();
  void update();
};

typedef cEnvironment  env;
