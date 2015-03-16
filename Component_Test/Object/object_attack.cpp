
#include "object.h"
#include "object_attack.h"


cObjectAttack::cObjectAttack(cObject* obj) :
cObjectInterface(obj),
m_attack(0) {

  std::cout << "�U���ł���悤�ɂȂ����I" << std::endl;
  std::cout << std::endl;
}


cObjectAttack::~cObjectAttack() {
  std::cout << "�U�� ";
}


bool cObjectAttack::isAttack() {
  return m_attack != 0;
}


void cObjectAttack::powerUp() {
  std::cout << "�U���͏㏸�I" << std::endl;
  m_attack = 10;
}


void cObjectAttack::update() {
  std::cout << "�L�����N�^�[�̍U���I" << std::endl;
  std::cout << "..�U���� = " << m_attack << std::endl;
}
