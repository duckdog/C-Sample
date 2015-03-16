
#pragma once
#include "../common.h"
#include "object_move.h"
#include "object_attack.h"


class cObject {
  cObjectMove* m_move;
  cObjectAttack* m_attack;

public:
  cObject();
  ~cObject();

  void componentInit(cObject*);

  bool isAttack();

  void update();
  void draw();
};
