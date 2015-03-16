
#pragma once
#include "../common.h"
#include "object_interface.h"


class cObjectAttack : public cObjectInterface {
  int m_attack;

public:
  cObjectAttack(cObject*);
  ~cObjectAttack();

  bool isAttack();
  void powerUp();

  void update();
};
