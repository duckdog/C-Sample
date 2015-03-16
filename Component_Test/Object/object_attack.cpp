
#include "object.h"
#include "object_attack.h"


cObjectAttack::cObjectAttack(cObject* obj) :
cObjectInterface(obj),
m_attack(0) {

  std::cout << "攻撃できるようになった！" << std::endl;
  std::cout << std::endl;
}


cObjectAttack::~cObjectAttack() {
  std::cout << "攻撃 ";
}


bool cObjectAttack::isAttack() {
  return m_attack != 0;
}


void cObjectAttack::powerUp() {
  std::cout << "攻撃力上昇！" << std::endl;
  m_attack = 10;
}


void cObjectAttack::update() {
  std::cout << "キャラクターの攻撃！" << std::endl;
  std::cout << "..攻撃力 = " << m_attack << std::endl;
}
