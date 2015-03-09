
#include "common.h"
#include "Player.h"
#include "lib/random.hpp"
#include <ctime>

// TIPS: コンテナを使うときは、コンテナと同じ名前の
//     : ファイルを必ずインクルードする
#include <list>
// イテレーター（iterator）の必要性を知ってもらうために
// 違うコンテナを使います

//#include <vector>
// std::vector が使えたのは、
// たまたま、先生のライブラリのどこかでインクルードしてた

// NOTICE:
// * 不要なコメントがあれば削除しても大丈夫
// * 違いを把握しやすいように、以前のコードを残しています
// * 一部のデータは common.h に引っ越し

/*
struct Enemy {
  float x;
  float y;
  bool isDead;
}enemy;

struct PlayerShot {
  float x;
  float y;
  float speed;
  bool judge;
  bool isDead;
}P_shot;

struct EnemyShot {
  float x;
  float y;
  float speed;
  bool judge;
  bool isDead;
}E_shot;
*/

// ショットの情報
// FIXME: 今の状態なら Vec2f で同じことができる
//  TIPS: 追加したい情報が増えてきたらファイル分けしよう
struct Shot {
  float x;
  float y;
};


/*
PlayerShot createShot(float player_x, float player_y) {
  PlayerShot P_shot;
  P_shot.isDead = false;
  P_shot.x = player_x + 25;
  P_shot.y = player_y + 85;

  return P_shot;
}
*/

// ショット発射したときのデータを作る
Shot CreateShot(const float pos_x, const float pos_y) {

  // 仮のデータを入れる変数を作る
  Shot temp;

  // 受け取った座標をショットの発射位置にする
  temp.x = pos_x;
  temp.y = pos_y;

  return temp;
}


int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT,
             false, false);
  /*
  Init();

  P_shot.speed = 15;
  unsigned int i = 0;
  unsigned int e = 0;
  int counter = 0;

  enemy.x = -350;
  enemy.y = 400;
  enemy.isDead = false;
  float enemy_x = 0;
  float enemy_y = 0;

  std::vector<PlayerShot>P_shots;
  std::vector<PlayerShot>::iterator it;

  it = P_shots.begin();
  */

  /* まずは宣言から */

  // 乱数
  // TIPS: u_int = unsigned int ※先生のライブラリ限定
  Random rand;
  rand.setSeed(u_int(time(nullptr)));

  // キャラクターの情報
  Character player;
  std::list<Character> enemy;
  const Vec2f PlayerOffset(PlayerSize_W / 2,
                           PlayerSize_H / 2);

  // ショットの情報
  std::list<Shot> p_shot;
  std::list<Shot>::iterator p_it;
  int shot_interval = 0;


  /* 初期化処理 */

  PlayerInit(player);

  // TODO: 敵の初期化を行う

  /* メインループ */

  while (env.isOpen()) {
    // TIPS: １フレームごとの更新処理

    /*
    // 弾の生成
    if (counter > 0)
      counter--;
    if (env.isPressKey(GLFW_KEY_SPACE) && P_shots.size() != Bullet::MAX) {
      if (counter <= 0) {
        P_shots.push_back(createShot(player.x, player.y));
        counter = 3;
      }
    }
    */

    // ショットの発射タイマーを減らす
    if (shot_interval > 0) { --shot_interval; }

    // ショット発射
    if (env.isPressKey(SPACE) && shot_interval == 0) {
      p_shot.push_back(CreateShot(player.x, player.y));
      shot_interval = INTERVAL;
    }

    // 自機の移動処理
    PlayerMove(env, player);

    // ショットの移動処理
    // TIPS: とりあえず移動だけしておく
    for (auto& it : p_shot) { it.y += SHOT_SPEED; }

    // Range_Based_For という for 文の書き方
    // 配列、コンテナのサイズを自動的に判断して繰り返す
    
    // 詳細は、先生の発表ネタの中に c11c14.pdf という
    // ファイルがあるはずだから、それを見てみよう

    // 画面外のショットを削除
    p_it = p_shot.begin();
    for (auto& it : p_shot) {

      // ショットが画面外か判定
      if (it.y > HEIGHT / 2) {
        p_shot.erase(p_it);

        // 削除したらイテレーターが死ぬので処理を抜ける
        break;
      }

      // イテレーターを次のショットにシフト
      ++p_it;
    }

    env.setupDraw();
    // TIPS: 基本的に、ここには表示処理のみを書く
    //     : 何故そうするのかは考えてみよう

    /*
    // 弾の移動
    for (i = 0; i < P_shots.size(); ++i) {
      P_shots[i].y += P_shot.speed;
      drawFillCircle(P_shots[i].x, P_shots[i].y, 5, 5, 10,
                     Color(1, 1, 1));

      // 弾の消滅条件 
      if (P_shots[i].y > 1200) {
        P_shots[i].isDead = true;
      }
    }

    for (i = 0; i < P_shots.size(); ++i) {
      if (!P_shots[i].isDead) {
        break;
      }
    }
    if (i == P_shots.size()) {
      P_shots.clear();
    }

    // 敵の処理
    for (e = 0; e < 10; ++e) {
      enemy_x = enemy.x + 70 * e;
      drawFillBox(enemy_x, enemy.y, 60, 60,
                  Color(1, 1, 1));
    }
    */

    // プレイヤー
    drawFillBox(player.x, player.y, 50, 80,
                Color(1, 1, 1),
                0, Vec2f(1, 1), PlayerOffset);

    // 敵
    // TODO: 表示処理を作る

    // ショット
    for (auto& it : p_shot) {
      drawFillCircle(it.x, it.y,
                     SHOT_SIZE, SHOT_SIZE,
                     SHOT_DIVISION,
                     Color(1, 1, 0));
    }

    env.update();
  }
}
