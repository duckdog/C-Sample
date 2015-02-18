
#include "ball.h"

typedef cBall  ball;


// TIPS: �d��
const float g_ = 1.0f;

// TIPS: ��ʒ[�̏��
// FIXME: ���������������@�����肻���ȋC������
const float leftEdge = -WIDTH / 2;
const float rightEdge = WIDTH / 2;
const float topEdge = HEIGHT / 2;
const float bottomEdge = -HEIGHT / 2;

// �{�[���̃T�C�Y�Ȃ�
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

  // �����W�̔��ˏ���
  if (data_.pos_.x() < -WIDTH / 2 ||
      data_.pos_.x() > WIDTH / 2) {

    // TIPS: ���x�𔽑Ε����ɂ���
    data_.speed_.x() *= -1;

    // TIPS: ��ʒ[�ƌ��݂̈ʒu���r�A
    // * ���[��菬������΍��[�ɖ߂� (std::max())
    // * �E�[���傫����ΉE�[�ɖ߂� (std::min())
    data_.pos_.x() =
      std::min(rightEdge,
      std::max(data_.pos_.x(), leftEdge));

    // * ���ꂼ��A��r�������ʁA�傫���ق��A�������ق���Ԃ�
    // * ���[��菬���� = ���̉�ʊO�ɂ͂ݏo�� = ���[���u�傫���v
    // * �E�[���傫�� = �E�̉�ʊO�ɂ͂ݏo�� = �E�[���u�������v
    // * ��₱�������ǁA�֗��Ȏg�����Ȃ̂ł��Њo���Ă�����

    // * ���Ȃ݂ɁA�搶�̃T���v�� camera �ł��g�p���Ă���
  }

  // �����W�̔��ˏ���
  // TIPS: ��ɓ���
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
