
#include "object.h"
#include "object_move.h"


cObjectMove::cObjectMove(cObject* obj) :
cObjectInterface(obj),
m_pos_x(0),
m_pos_y(0) {

  std::cout << "�ړ��ł���悤�ɂȂ����I" << std::endl;
  std::cout << std::endl;
}


cObjectMove::~cObjectMove() {
  std::cout << "�ړ� ";
}


void cObjectMove::update() {
  if (m_obj->isAttack()) {
    std::cout << "�U�����͈ړ��ł��Ȃ��I" << std::endl;
    return;
  }

  std::cout << "�ړ����E�E�E" << std::endl;
  m_pos_x += 10;
  m_pos_y += 10;
}


void cObjectMove::getPos() {
  std::cout << "�������ɂ���I" << std::endl;
  std::cout << "..pos_x = " << m_pos_x << std::endl;
  std::cout << "..pos_y = " << m_pos_y << std::endl;
  std::cout << std::endl;
}
