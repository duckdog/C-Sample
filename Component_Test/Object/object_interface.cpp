
#include "object.h"
#include "object_interface.h"


cObjectInterface::cObjectInterface(cObject* obj) :
m_obj(obj) {

  std::cout << "機能を展開！" << std::endl;
}


cObjectInterface::~cObjectInterface() {
  std::cout << "機能を終了！" << std::endl;
}
