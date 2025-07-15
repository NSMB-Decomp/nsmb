#include "Base.hpp"

Base *Base::spawnParent(u16 p1, u32 p2, u32 p3) {
  return this->spawn(p1, 0, p2, p3);
}

void *Base::operator new(u32 count) { return ::operator new(count); }

bool Base::preCreate() { return true; }
bool Base::onCreate() { return true; }