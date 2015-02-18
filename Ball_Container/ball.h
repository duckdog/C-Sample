
#pragma once
#include "common.h"


enum {
  BallMax = 10,
};


class cBall {
  struct sBallData {
    Vec2f pos_;
    Vec2f speed_;
    Color color_;
  };

  sBallData data_;

public:
  cBall(const Vec2f&, Random&);

  void gravity();
  
  void update();
  void draw();
};
