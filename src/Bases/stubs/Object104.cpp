#include "Object104.hpp"
#include "Object103.hpp"
#include "../../ProcessManager.hpp"

void *Object104::create()
{
	return new Object104();
}

// 0x0218e1f0
ActorProfile Object104_Profile = { Object104::create, 104, 225, NULL };

s32 Object104::onDestroy() {
    return 1;
}

void Object104::pendingDestroy() {
}

u32 func_ov000_020a6d18(u32, u32);
bool Object104::onUpdate_0() {
  u32 uVar1;
  Base *iVar2;

  uVar1 = func_ov000_020a6d18(this->position.x, this->position.y);
  if ((uVar1 & 0x10000) != 0) {
    for (iVar2 = ProcessManager::getNextObjectByObjectID(0x67, 0); iVar2 != 0; iVar2 = ProcessManager::getNextObjectByObjectID(0x67, iVar2)) {
      if (this->_3f3 == (((Object103*)iVar2)->_4a8)) {
        ((Object103*)iVar2)->_4a9 = 1;
        this->destroy(0);
        return true;
      }
    }
  }
  this->destroyInactive(0);
  return true;
}

s32 Object104::onCreate() {
    this->_3f3 = this->settings & 0xf;
    this->visible = 0;
    return 1;
}
