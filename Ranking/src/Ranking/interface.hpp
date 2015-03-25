
#pragma once

class cRanking;


class cInterface {
protected:
  cRanking* m_instance;

  cInterface(cRanking* instance) :
    m_instance(instance) {}

public:
  virtual void update() = 0;
};
