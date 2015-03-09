
#include "Player.h"

// Player player;
// グローバル変数は可能な限り、使うのを避けよう
// データが大きいほど、プロジェクト自体の規模が大きくなるほど、
// メモリを無駄に食いつぶすことのリスクが大きくなる


/*
void Init() {
  player.x = -25.0;
  player.y = -300.0;
  player.life = 3;   // <- これは必要？
  player.life = 5;
  player.speed_x = 8.0;
  player.slow_speed_x = 4.0;
}

void PlayerMove(AppEnv& env, Player& player) {
  // 自機の移動処理
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

// プレイヤーの初期化
void PlayerInit(Character& player) {
  player.x = 0;
  player.y = DefaultPos_Y;
  player.life = PlayerLife;
}


// プレイヤー移動
void PlayerMove(AppEnv& env, Character& player) {

  // 画面端の情報
  // TIPS: 書き換える必要のないもの、
  //     : 書き換えてはいけないものは const をつけよう
  const float leftEdge = -WIDTH / 2 + PlayerSize_W / 2;
  const float rightEdge = WIDTH / 2 - PlayerSize_W / 2;

  // 移動速度
  // TIPS: v = velocity の意味
  float move_v = MoveSpeed;

  // 左シフトキーが押されていれば速度を落とす
  if (env.isPressKey(SHIFT)) { move_v *= 0.5f; }

  // キーが入力されていれば移動
  if (env.isPressKey(MOVE_L)) {
    player.x -= move_v;
  }
  else if (env.isPressKey(MOVE_R)) {
    player.x += move_v;
  }

  // 画面外に移動しようとしていたら戻す
  /*
  if (player.x < leftEdge) {
    player.x = leftEdge;
  }
  if (player.x > rightEdge) {
    player.x = rightEdge;
  }
  */

  // TIPS: if でもいいけど、もっとすっきりする書き方
  player.x = std::max(player.x, leftEdge);    // 左端に戻す
  player.x = std::min(player.x, rightEdge);   // 右端に戻す
}
