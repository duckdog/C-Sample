
#include "object.h"


cObject::cObject() {
  std::cout << "キャラクター登場！" << std::endl;
  std::cout << std::endl;
}


// FIXME: このやり方はあまり良くないので好きじゃない
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
  std::cout << "キャラクター退場！" << std::endl;
}


//  TIPS: 部品の初期化を行う
//      : 各部品に自分のポインタを渡す
// FIXME: このやり方はあまり良くないので好きじゃない
void cObject::componentInit(cObject* obj) {
  if (m_move == nullptr)
    m_move = new cObjectMove(this);

  if (m_attack == nullptr)
    m_attack = new cObjectAttack(this);
}


// TIPS: 別の部品に渡す「部品の状態」だけを抽出する
bool cObject::isAttack() {
  return m_attack->isAttack();
}


void cObject::update() {
  std::cout << "キャラクター行動開始！" << std::endl;

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
  std::cout << "キャラクター表示！" << std::endl;
  m_move->getPos();
  std::cout << std::endl;
}
