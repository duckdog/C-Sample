
#pragma once
#include "../common.h"

class cObject;


class cObjectInterface {
protected:
  cObject* m_obj;

  cObjectInterface(cObject* obj);
  ~cObjectInterface();
};
