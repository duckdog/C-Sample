
#include "object.h"


cObject::cObject() {
  std::cout << "�L�����N�^�[�o��I" << std::endl;
  std::cout << std::endl;
}


// FIXME: ���̂����͂��܂�ǂ��Ȃ��̂ōD������Ȃ�
cObject::~cObject() {
  if (m_move != nullptr) {
    delete m_move;
    m_move = nullptr;
  }

  if (m_attack != nullptr) {
    delete m_attack;
    m_attack = nullptr;
  }

  std::cout << std::endl;
  std::cout << "�L�����N�^�[�ޏ�I" << std::endl;
}


//  TIPS: ���i�̏��������s��
//      : �e���i�Ɏ����̃|�C���^��n��
// FIXME: ���̂����͂��܂�ǂ��Ȃ��̂ōD������Ȃ�
void cObject::componentInit(cObject* obj) {
  if (m_move == nullptr)
    m_move = new cObjectMove(this);

  if (m_attack == nullptr)
    m_attack = new cObjectAttack(this);
}


// TIPS: �ʂ̕��i�ɓn���u���i�̏�ԁv�����𒊏o����
bool cObject::isAttack() {
  return m_attack->isAttack();
}


void cObject::update() {
  std::cout << "�L�����N�^�[�s���J�n�I" << std::endl;

  m_move->update();
  std::cout << std::endl;

  m_attack->update();
  std::cout << std::endl;

  m_attack->powerUp();
  std::cout << std::endl;

  m_attack->update();
  std::cout << std::endl;

  m_move->update();
  std::cout << std::endl;
}


void cObject::draw() {
  std::cout << "�L�����N�^�[�\���I" << std::endl;
  m_move->getPos();
  std::cout << std::endl;
}
