
#pragma once
#include "common.h"

/*
struct Player {
  float x;
  float y;
  float speed_x;
  float slow_speed_x;
  float life;
};

// �X�s�[�h�͕ς��Ȃ����́i���Ǝv���j�̂ŁA
// �f�[�^�Ƃ��Ď��K�v�͂Ȃ�
// life �� float �^�Ȃ̂́A�̗̓Q�[�W��\�����悤�Ƃ����H
*/

// �L�����N�^�[�̏��
// TIPS: �v���C���[���G�����������x�[�X�ɂ���
struct Character {
  float x;
  float y;
  float life;
};


// �ǉ�
// TIPS: �L�����N�^�[�̃p�����[�^�Ȃ�
enum CharacterInfo {
  EnemyLife = 1,
  PlayerLife = 5,

  MoveSpeed = 8,

  PlayerSize_W = 50,
  PlayerSize_H = 80,
  DefaultPos_Y = -300,
};


// �ǉ�
// TIPS: �L�[�{�[�h���͂̃L�[���ꗗ
enum KeyList {
  MOVE_L = GLFW_KEY_LEFT,
  MOVE_R = GLFW_KEY_RIGHT,
  SHIFT  = GLFW_KEY_LEFT_SHIFT,
  SPACE  = GLFW_KEY_SPACE,
};


//void Init();
//void PlayerMove(AppEnv&, Player&);
// PlayerMove() �̖��O�̕t������ OK
// Init() �ł́A�������������悤�Ƃ��Ă邩�킩��Ȃ��̂ŁA
// �v���C���[�̏������Ȃ�A���ꂪ�킩��悤�Ȗ��O�ɂ��悤

void PlayerInit(Character&);
void PlayerMove(AppEnv&, Character&);
