
#include "Object/object.h"


int main() {
  cObject obj;
  obj.componentInit(&obj);

  obj.draw();

  obj.update();
  obj.draw();
}
