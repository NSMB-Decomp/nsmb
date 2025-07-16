#include "Base.hpp"

Base *Base::spawnParent(u16 overlay_id, u32 b, u32 c) {
  return this->spawn(overlay_id, 0, b, c);
}
Base *Base::spawnChild(u16 overlay_id, Base *b, u32 c, u32 d) {
  if (b != (Base *)0x00) {
    return this->spawn(overlay_id, &b->process_link, c, d);
  }
  return (Base *)0x00;
}

void Base::unloadSceneOverlay() {
  if (Base::data_0208fb00 != 0x00) {
    ((void (*)(void))Base::data_0208fb00)();
  }
}

void Base::loadSceneOverlay(u32 a) {
  if (Base::data_0208fafc != 0x00) {
    ((void (*)(u32))Base::data_0208fafc)(a);
  }
}

Base *spawn(u16 overlay_id, ProcessLink *b, u32 c, u32 d) {
  Base::data_0208fae8 = 0x01;
  Base::data_0208faf0 = overlay_id;
  if (overlay_id == 3) {
    return (Base *)0x00;
  }
}

void Base::setSpawnParams(u16 a, u32 b, u32 c, u8 d) {
  Base::data_0208fb04 = c;
  Base::data_0208faf4 = a;
  Base::data_0208faec = d;
  Base::data_0208faf8 = b;
}

void Base::create() {
  processCreate();
  if (this->pending_destroy) {
    return;
  }
  if (this->__1 != 0) {
    return;
  }
  if (this->state != 0) {
    return;
  }
  //if (ProcessManager::CurrentTask != Create) {
  //  func_020438e8(&ProcessManager::CreateTask,&(this->_).processLink.update);
  //  return;
  //}
  this->__2 = 0x01;
}

void Base::operator delete(void *ptr) { return ::operator delete(ptr); }

void *Base::operator new(u32 count) { return ::operator new(count); }
bool Base::onHeapCreated() { return true; }

Base *Base::getParent() {
  SceneNode *a = this->process_link.connect.parent;
  if (a) {
    return a->object;
  } else {
    return (Base *)0x0;
  }
};

void Base::destroy() {
  if (!this->pending_destroy&& this->state != 0x02) {
    this->pending_destroy = true;
    this->pendingDestroy();
  }
}

void Base::pendingDestroy() {}
bool Base::onDestroy() { return true; }
bool Base::preCreate() { return true; }
bool Base::onCreate() { return true; }