
#include "object.h"
#include "object_attack.h"


cObjectAttack::cObjectAttack(cObject* obj) :
cObjectInterface(obj),
m_attack(0) {

  std::cout << "UŒ‚‚Å‚«‚é‚æ‚¤‚É‚È‚Á‚½I" << std::endl;
  std::cout << std::endl;
}


cObjectAttack::~cObjectAttack() {
  std::cout << "UŒ‚ ";
}


bool cObjectAttack::isAttack() {
  return m_attack != 0;
}


void cObjectAttack::powerUp() {
  std::cout << "UŒ‚—Íã¸I" << std::endl;
  m_attack = 10;
}


void cObjectAttack::update() {
  std::cout << "ƒLƒƒƒ‰ƒNƒ^[‚ÌUŒ‚I" << std::endl;
  std::cout << "..UŒ‚—Í = " << m_attack << std::endl;
}
