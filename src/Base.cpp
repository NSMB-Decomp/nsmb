#include "Base.hpp"
#include "Base_bss.hpp"
#include "AAA.hpp"

Base::Base() // why are there two Base::Base created as a result of this?
{
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
Base::~Base() {} // Why does this one create 3???
bool Base::onCreate() { return true; }
bool Base::preCreate() { return true; }
bool Base::postCreate() {}
bool Base::onDestroy() { return true; }
bool Base::preDestroy()
{
  if (!(
          (this->__5 == 0 || func_0204d82c()) &&
          this->process_link.connect.firstChild == (SceneNode *)0x0))

  {
    return false;
  }
  else
  {
    return true;
  };
}
void Base::postDestroy()
{
}
void Base::pendingDestroy() {}
void Base::destroy()
{
  bool cond1 = (this->pending_destroy == false) &&
               !this->state == two;
  if (cond1)
  {
    this->pending_destroy = true;
    this->pendingDestroy();
  }
}
Base *Base::getParent()
{
  SceneNode *a = this->process_link.connect.parent;
  if (a)
  {
    return a->object;
  }
  else
  {
    return (Base *)0x0;
  }
};
bool Base::prepareResourcesSafe(u32 a, u32 b)
{
}
bool Base::prepareResourcesFast(u32 a, u32 b)
{
}
bool Base::onHeapCreated() { return true; }
void *Base::operator new(u32 count)
{
  Base *ptr = (Base *)func_02045040(data_0208b720, count, -4);
  if (ptr != (Base *)0x0)
  {
    func_02066fe8(ptr, 0, count);
    return ptr;
  }
  return (Base *)0x0;
}
void Base::operator delete(void *ptr)
{
  func_02044d94(data_0208b720, ptr);
}
void Base::create()
{
  processCreate();
  if (this->pending_destroy)
  {
    return;
  }
  if (this->__1 != 0)
  {
    return;
  }
  if (!this->state == pendingInit)
  {
    return;
  }
  if ((bool)(CurrentTask == 2) ? 1 : 0)
  {
    this->__2 = 0x01;
    return;
  }
  func_020438e8(&CreateTask, &this->process_link.update);
  return;
}
void Base::processCreate()
{
  func_01ffd524(
      this,
      data_02085240[0],
      data_02085240[1],
      data_02085238[0],
      data_02085238[1],
      data_02085228[0],
      data_02085228[1]);
}
u32 Base::processDestroy()
{
  u16 object_id = this->object_id;
  u32 ret = func_01ffd524(
      this,
      data_02085230[0],
      data_02085230[1],
      data_02085248[0],
      data_02085248[1],
      data_02085250[0],
      data_02085250[1]);
  if (ret == 1)
  {
    unloadSceneOverlay();
  }
  return ret;
}
bool Base::hasChildPendingCreation()
{
  SceneNode *next = this->process_link.connect.func_020439f0();
  SceneNode *cur = this->process_link.connect.firstChild;

  while (cur != next || cur != (SceneNode *)0x0)
  {
    if ((*cur->object).state == pendingInit)
    {
      return true;
    }
    cur = cur->func_02043a2c();
  };

  // for (cur = this->process_link.connect.firstChild;
  //      (cur != (SceneNode *)0x0 && (cur != next));
  //      cur = cur->func_02043a2c())
  //{
  //   if ((*cur->object).state == zero)
  //   {
  //     return true;
  //   }
  // }

  return false;
}
void Base::setSpawnParams(u16 a, ProcessLink *b, u32 c, u8 d)
{
  SpawnParam3 = c;
  SpawnParam1 = a;
  SpawnParam4 = d;
  SpawnParam2 = b;
}
Base *Base::spawn(u16 overlay_id, ProcessLink *b, u32 c, u8 d)
{
  data_0208faf0 = overlay_id;
  data_0208fae8 = 1;
  u32 new_overlay = Base::loadSceneOverlay(overlay_id);
  if (new_overlay == 3)
  {
    return (Base *)0x00;
  }
  data_0208fae8 = 2;
  setSpawnParams(overlay_id, b, c, d);
  data_0208fae8 = 3;
  Base *ret = (CurrentProfileTable)[overlay_id]->constructor();
  if (ret == (Base *)0x00)
  {
    data_0208faf0 = 0xFFFF;
    data_0208fae8 = 0;
    return ret;
  }
  else
  {
    data_0208fae8 = 4;
    ret->create();
    data_0208fae8 = 0;
    data_0208faf0 = 0xFFFF;
    return ret;
  }
}
u32 Base::loadSceneOverlay(u16 a)
{
  if (data_0208fafc != 0x00)
  {
    ((void (*)(u16))data_0208fafc)(a);
  }
  else
  {
    return 2;
  }
}
void Base::unloadSceneOverlay()
{ // Not sure if the arg this accepts is "this" or arg1
  if (data_0208fb00 != 0x00)
  {
    ((void (*)(Base *))data_0208fb00)(this);
  }
}
Base *Base::spawnChild(u16 overlay_id, Base *b, u32 c, u8 d)
{
  if (b != (Base *)0x00)
  {
    return b->spawn(overlay_id, &b->process_link, c, d);
  }
  return (Base *)0x00;
}
Base *Base::spawnParent(u16 a, u32 b, u8 c)
{
  return Base::spawn(a, 0, b, c);
}
