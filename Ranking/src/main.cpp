
int main() {
  AppEnv env(WIDTH, HEIGHT);

  while (env.isOpen()) {
    env.begin();   // 描画開始 env.setupDraw() と同じ

    // TIPS: 色を指定できるようになった
    drawFillCircle(0, 0, 50, 50,
                   50, Color::white);

    // TIPS: 昔ながらの方法も使えます
    drawFillCircle(0, 0, 25, 25,
                   50, Color(0, 0, 1));

    env.end();     // 更新 env.update() と同じ
  }
}
