
#include "resource.h"
#include <string>


cResource::cResource() {
  struct SpriteInfo {
    SpriteID id;
    std::string file_pass;
  };

  const SpriteInfo Table[] = {
    { LargePoint, "res/point_large.png" },
    { SmallPoint, "res/point_small.png" },
    { BackGround, "res/background.png"  },
  };

  for (auto& it : Table) {
    m_sprite.insert(std::make_pair(it.id, Texture(it.file_pass)));
  }
}


cResource* cResource::get() {
  static cResource s_instance;
  return &s_instance;
}


Texture* cResource::Sprite(const SpriteID id) {
  auto& it = m_sprite.find(id);
  return &it->second;
}
