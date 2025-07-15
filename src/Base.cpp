#include "Base.hpp"

bool Base::spawnParent(u16 p1, u32 p2, u32 p3) {
  this->spawn(p1, 0, p2, p3);
  return true;
}

bool Base::onCreate() {
  return true;
}