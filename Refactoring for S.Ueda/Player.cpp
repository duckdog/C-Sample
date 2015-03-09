
#include "Player.h"

// Player player;
// �O���[�o���ϐ��͉\�Ȍ���A�g���̂�����悤
// �f�[�^���傫���قǁA�v���W�F�N�g���̂̋K�͂��傫���Ȃ�قǁA
// �������𖳑ʂɐH���Ԃ����Ƃ̃��X�N���傫���Ȃ�


/*
void Init() {
  player.x = -25.0;
  player.y = -300.0;
  player.life = 3;   // <- ����͕K�v�H
  player.life = 5;
  player.speed_x = 8.0;
  player.slow_speed_x = 4.0;
}

void PlayerMove(AppEnv& env, Player& player) {
  // ���@�̈ړ�����
  if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350) {
    player.x += player.slow_speed_x;
  }
  else if (env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350) {
    player.x += player.speed_x;
  }
  if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400) {
    player.x -= player.slow_speed_x;
  }
  else if (env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400) {
    player.x -= player.speed_x;
  }
  if (player.x >= 350) {
    player.x = 350;
  }
  if (player.x <= -400) {
    player.x = -400;
  }
}
*/

// �v���C���[�̏�����
void PlayerInit(Character& player) {
  player.x = 0;
  player.y = DefaultPos_Y;
  player.life = PlayerLife;
}


// �v���C���[�ړ�
void PlayerMove(AppEnv& env, Character& player) {

  // ��ʒ[�̏��
  // TIPS: ����������K�v�̂Ȃ����́A
  //     : ���������Ă͂����Ȃ����̂� const �����悤
  const float leftEdge = -WIDTH / 2 + PlayerSize_W / 2;
  const float rightEdge = WIDTH / 2 - PlayerSize_W / 2;

  // �ړ����x
  // TIPS: v = velocity �̈Ӗ�
  float move_v = MoveSpeed;

  // ���V�t�g�L�[��������Ă���Α��x�𗎂Ƃ�
  if (env.isPressKey(SHIFT)) { move_v *= 0.5f; }

  // �L�[�����͂���Ă���Έړ�
  if (env.isPressKey(MOVE_L)) {
    player.x -= move_v;
  }
  else if (env.isPressKey(MOVE_R)) {
    player.x += move_v;
  }

  // ��ʊO�Ɉړ����悤�Ƃ��Ă�����߂�
  /*
  if (player.x < leftEdge) {
    player.x = leftEdge;
  }
  if (player.x > rightEdge) {
    player.x = rightEdge;
  }
  */

  // TIPS: if �ł��������ǁA�����Ƃ������肷�鏑����
  player.x = std::max(player.x, leftEdge);    // ���[�ɖ߂�
  player.x = std::min(player.x, rightEdge);   // �E�[�ɖ߂�
}
