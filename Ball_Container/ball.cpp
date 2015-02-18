
#include "ball.h"

typedef cBall  ball;


// TIPS: 重力
const float g_ = 1.0f;

// TIPS: 画面端の情報
// FIXME: もう少しいい方法がありそうな気がする
const float leftEdge = -WIDTH / 2;
const float rightEdge = WIDTH / 2;
const float topEdge = HEIGHT / 2;
const float bottomEdge = -HEIGHT / 2;

// ボールのサイズなど
enum {
  BallSize = 10,
  BallDivision = 20,
};


cBall::cBall(const Vec2f& pos,
             Random& random) {
  data_.pos_ = pos;

  data_.speed_.x() = random.fromFirstToLast(-10.0f, 10.0f);
  data_.speed_.y() = random.fromFirstToLast(-10.0f, 10.0f);

  data_.color_.red()   = random.fromFirstToLast(0.25f, 1.0f);
  data_.color_.green() = random.fromFirstToLast(0.25f, 1.0f);
  data_.color_.blue()  = random.fromFirstToLast(0.25f, 1.0f);
}


void ball::gravity() {
  data_.speed_.y() -= g_;
}


void ball::update() {
  data_.pos_.x() += data_.speed_.x();
  data_.pos_.y() += data_.speed_.y();

  // ｘ座標の反射処理
  if (data_.pos_.x() < -WIDTH / 2 ||
      data_.pos_.x() > WIDTH / 2) {

    // TIPS: 速度を反対方向にする
    data_.speed_.x() *= -1;

    // TIPS: 画面端と現在の位置を比較、
    // * 左端より小さければ左端に戻す (std::max())
    // * 右端より大きければ右端に戻す (std::min())
    data_.pos_.x() =
      std::min(rightEdge,
      std::max(data_.pos_.x(), leftEdge));

    // * それぞれ、比較した結果、大きいほう、小さいほうを返す
    // * 左端より小さい = 左の画面外にはみ出る = 左端が「大きい」
    // * 右端より大きい = 右の画面外にはみ出る = 右端が「小さい」
    // * ややこしいけど、便利な使い方なのでぜひ覚えておこう

    // * ちなみに、先生のサンプル camera でも使用している
  }

  // ｙ座標の反射処理
  // TIPS: 上に同じ
  if (data_.pos_.y() < -HEIGHT / 2 ||
      data_.pos_.y() > HEIGHT / 2) {

    data_.speed_.y() *= -1;

    data_.pos_.y() =
      std::min(topEdge,
      std::max(data_.pos_.y(), bottomEdge));
  }
}


void ball::draw() {
  drawFillCircle(data_.pos_.x(), data_.pos_.y(),
                 BallSize, BallSize, BallDivision,
                 data_.color_);
}
