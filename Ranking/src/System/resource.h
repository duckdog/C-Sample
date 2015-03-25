
#pragma once
#include "../common.hpp"
#include <map>


enum SpriteID {
  LargePoint,
  SmallPoint,
  BackGround,

  All_Sprite,
};


class cResource {
  cResource();

  std::map<SpriteID, Texture> m_sprite;

public:
  static cResource* get();

  Texture* Sprite(const SpriteID id);
};
