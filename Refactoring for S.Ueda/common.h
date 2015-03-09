
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


enum Window {
  WIDTH  = 800,
  HEIGHT = 950,
};


// ショットの設定データ
// TIPS: ショット専用にファイル分けしたら、
//     : ヘッダーファイルに移動したほうがいい
enum ShotInfo {
  //SHOT_MAX = 50,

  // 追加
  SHOT_SIZE = 5,
  SHOT_DIVISION = 10,

  SHOT_SPEED = 15,
  INTERVAL = 3,   // 発射間隔
};
