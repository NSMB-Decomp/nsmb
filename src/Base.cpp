#include "Base.hpp"

Base::Base() {
  ProcessLink pl = this->process_link;
  pl.connect.object = this;
  pl.update._.prev = (ProcessNode *)0x00;
  pl.update._.next = (ProcessNode *)0x00;
  pl.update._.object = this;
  pl.update.currentPriority = 0;
  pl.update.sortPriority = 0;
  pl.render._.prev = (ProcessNode *)0x00;
  pl.render._.next = (ProcessNode *)0x00;
  pl.render._.object = this;
  pl.render.currentPriority = 0;
  pl.render.sortPriority = 0;
  pl.idLookup.prev = (ProcessNode *)0x00;
  pl.idLookup.next = (ProcessNode *)0x00;
  pl.idLookup.object = this;
}
bool Base::onCreate() { return true; }
bool Base::preCreate() { return true; }
bool Base::onDestroy() { return true; }
void Base::pendingDestroy() {}
void Base::destroy() {
  bool cond = (this->pending_destroy == false) && this->state == two;
  if (cond) {
    this->pending_destroy = true;
    this->pendingDestroy();
  }
}
Base *Base::getParent() {
  SceneNode *a = this->process_link.connect.parent;
  if (a) {
    return a->object;
  } else {
    return (Base *)0x0;
  }
};
bool Base::onHeapCreated() { return true; }
void *Base::operator new(u32 count) { return ::operator new(count); }
void Base::operator delete(void *ptr) { return ::operator delete(ptr); }
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
  // if (ProcessManager::CurrentTask != Create) {
  //   func_020438e8(&ProcessManager::CreateTask,&(this->_).processLink.update);
  //   return;
  // }
  this->__2 = 0x01;
}
u32 Base::processDestroy() {
  u16 object_id = this->object_id;
 // u32 ret = process(this,(FunctionPtr *)&PrefetchAbort,1,(FunctionPtr *)&DataAbort,1,
 //                 (FunctionPtr2 *)&NotUsed,1);
 u32 ret = 0;
  if (ret == 1) {
    unloadSceneOverlay();
  }
  return ret;
}
void Base::setSpawnParams(u16 a, u32 b, u32 c, u8 d) {
  Base::SpawnParam3 = c;
  Base::SpawnParam1 = a;
  Base::SpawnParam4 = d;
  Base::SpawnParam2 = b;
}
//Base *spawn(u16 overlay_id, ProcessLink* b, u32 c, u32 d) {
//  //Base::data_0208fae8 = 0x01;
//  //Base::data_0208faf0 = overlay_id;
//  //if (overlay_id == 3) {
//  //  return (Base *)0x00;
//  //}
//}
u32 Base::loadSceneOverlay(u32 a) {
  if (Base::data_0208fafc != 0x00) {
    ((void (*)(Base*))Base::data_0208fafc)(this);
  } else {
    return 2;
  }
}
void Base::unloadSceneOverlay() { // Not sure if the arg this accepts is "this" or arg1
  if (Base::data_0208fb00 != 0x00) {
    ((void (*)(Base*))Base::data_0208fb00)(this);
  }
}
Base *Base::spawnChild(u16 overlay_id, Base* b, u32 c, u32 d) {
  if (b != (Base *)0x00) {
    return b->spawn(overlay_id, &b->process_link, c, d);
  }
  return (Base *)0x00;
}
Base* Base::spawnParent(u16 a, u32 b, u32 c) {
  return Base::spawn(a, 0, b, c);
}
