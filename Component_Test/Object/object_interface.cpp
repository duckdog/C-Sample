
#include "object.h"
#include "object_interface.h"


cObjectInterface::cObjectInterface(cObject* obj) :
m_obj(obj) {

  std::cout << "�@�\��W�J�I" << std::endl;
}


cObjectInterface::~cObjectInterface() {
  std::cout << "�@�\���I���I" << std::endl;
}
