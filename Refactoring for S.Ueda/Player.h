
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

// スピードは変わらないもの（だと思う）ので、
// データとして持つ必要はない
// life が float 型なのは、体力ゲージを表示しようとした？
*/

// キャラクターの情報
// TIPS: プレイヤーも敵も同じ情報をベースにする
struct Character {
  float x;
  float y;
  float life;
};


// 追加
// TIPS: キャラクターのパラメータなど
enum CharacterInfo {
  EnemyLife = 1,
  PlayerLife = 5,

  MoveSpeed = 8,

  PlayerSize_W = 50,
  PlayerSize_H = 80,
  DefaultPos_Y = -300,
};


// 追加
// TIPS: キーボード入力のキー情報一覧
enum KeyList {
  MOVE_L = GLFW_KEY_LEFT,
  MOVE_R = GLFW_KEY_RIGHT,
  SHIFT  = GLFW_KEY_LEFT_SHIFT,
  SPACE  = GLFW_KEY_SPACE,
};


//void Init();
//void PlayerMove(AppEnv&, Player&);
// PlayerMove() の名前の付け方は OK
// Init() では、何を初期化しようとしてるかわからないので、
// プレイヤーの初期化なら、それがわかるような名前にしよう

void PlayerInit(Character&);
void PlayerMove(AppEnv&, Character&);
