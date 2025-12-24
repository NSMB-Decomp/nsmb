#include "Base_bss.cpp"
#include "../Nitro/Nitro.hpp"

u32 data_02085224 = 1;
u32 data_02085248[2] = {0x10, 1};
u32 data_02085240[2] = {0x00, 1};
u32 data_02085238[2] = {0x04, 1};
u32 data_02085230[2] = {0x0C, 1};
u32 data_02085228[2] = {0x08, 1};
u32 data_02085250[2] = {0x14, 1};

Base::Base()
{
  void func_02043b58(ProcessLink *);

  ProcessLink *pl = &this->process_link;
  func_02043b58(pl);
  pl->connect.object = this;
  PriorityNode *update_node = &pl->update;
  update_node->_.prev = (ProcessNode *)0x00;
  update_node->_.next = (ProcessNode *)0x00;
  update_node->_.object = this;
  update_node->currentPriority = 0;
  update_node->sortPriority = 0;
  PriorityNode *render_node = &pl->render;
  render_node->_.prev = (ProcessNode *)0x00;
  render_node->_.next = (ProcessNode *)0x00;
  render_node->_.object = this;
  render_node->currentPriority = 0;
  render_node->sortPriority = 0;
  pl->idLookup.prev = (ProcessNode *)0x00;
  pl->idLookup.next = (ProcessNode *)0x00;
  pl->idLookup.object = this;

  this->guid = data_02085224;
  data_02085224 += 1;
  this->settings = SpawnParam3;
  this->object_id = SpawnParam1;
  this->_12 = SpawnParam4;

  SceneGraph_addChild(&ProcessManager::ConnectTask, pl, SpawnParam2);
  u32 id_index = ProcessManager::getIDIndex(&this->process_link);
  LinkedList_Prepend(&ProcessManager::idLookupProcesses[id_index], &this->process_link.idLookup);
  ObjectProfile *profile = CurrentProfileTable[this->object_id];

  u32 update_priority = profile->updatePriority;
  this->process_link.update.currentPriority = update_priority;
  this->process_link.update.sortPriority = update_priority;

  u32 render_priority = profile->renderPriority;
  this->process_link.render.currentPriority = render_priority;
  this->process_link.render.sortPriority = render_priority;

  Base *parent = this->getParent();
  if (parent != NULL)
  {
    u32 bVar1 = parent->skipFlags;
    if (((bVar1 & UpdateChildren) != 0) || ((bVar1 & Update) != 0))
    {
      this->skipFlags = (SkipFlags)(this->skipFlags | Update);
    }
    bVar1 = parent->skipFlags;
    if (((bVar1 & RenderChildren) != 0) || ((bVar1 & Render) != 0))
    {
      this->skipFlags = (SkipFlags)(this->skipFlags | Render);
    }
  }
}
Base::~Base()
{
  this->process_link.idLookup.unlink();
  this->process_link.render.unlink();
  this->process_link.update.unlink();
} // Why does this one create 3???
bool Base::onCreate() { return true; }
bool Base::preCreate() { return true; }
void Base::postCreate(u32 a)
{
  if (a != 2)
  {
    return;
  }
  LinkedList_Remove(&ProcessManager::CreateTask, &this->process_link.update);
  if ((bool)(ProcessManager::CurrentTask == Execute) ? 1 : 0)
  {
    this->pending_update = 1;
    return;
  }
  ProcessSet_add(&ProcessManager::ExecuteTask, &this->process_link.update);
  ProcessSet_add(&ProcessManager::DrawTask, &this->process_link.render);
  this->state = Active;
  return;
}
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
void Base::postDestroy(u32 a)
{
  void func_02045128();
  void func_0204d908();
  void func_02044ab0(Base *, void *);

  if (a != 2)
  {
    return;
  }
  SceneGraph_removeChild(&ProcessManager::ConnectTask, &this->process_link);
  u32 id_index = ProcessManager::getIDIndex(&this->process_link);
  LinkedList_Remove(&ProcessManager::idLookupProcesses[id_index], &this->process_link.idLookup);
  LinkedList_Remove(&ProcessManager::DestroyTask, &this->process_link.update);
  if (this->heap != NULL)
  {
    func_02045128();
  }
  if (this->__5 != NULL)
  {
    func_0204d908();
  }
  this->~Base();
  func_02044ab0(this, data_0208b720);
}
void Base::pendingDestroy() {}
void Base::destroy()
{
  if ((this->pending_destroy == false) &&
              (u8)(this->state == Inactive) == 0
          ? true
          : false) // Todo, is there a better syntax for this compiler bug?
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
  if (this->heap == NULL)
  {
    return true;
  }

  return false;
}
bool Base::prepareResourcesFast(u32 a, u32 b)
{
  Heap *user;
  Heap *heap;
  void *z;

  if (this->heap == NULL)
  {
    return true;
  }
  if (
      a != 0 &&
      (user = func_02045240(a, b, 0x20), user != (Heap *)0x0))
  {
    void *heap_ptr = (void *)((u32)(user->size) & 0x10);
    if (heap_ptr != NULL)
    {
      user->allocate(0x10, 0x10);
    }
    heap = user->setCurrent();
    u32 result = this->onHeapCreated();
    heap->setCurrent();
    if (
        heap_ptr == NULL &&
        (z = user->allocate(0x10, 0x10), z == NULL))
    {
      result = 0;
    }
    user->maxAllocationUnitSize();
    if (result == 0)
    {
      user->destroy();
    }
    else
    {
      this->heap = user;
      return true;
    }
  }
  this->destroy();
  return false;
}
bool Base::onHeapCreated() { return true; }
void *Base::operator new(u32 count)
{
  Base *ptr = (Base *)data_0208b720->allocate(count, -4);
  if (ptr != (Base *)0x0)
  {
    Nitro::func_02066fe8(ptr, 0, count);
    return ptr;
  }
  return (Base *)0x0;
}
void Base::operator delete(void *ptr)
{
  Heap_deallocate(data_0208b720, ptr);
}
void Base::create()
{
  processCreate();
  if (this->pending_destroy)
  {
    return;
  }
  if (this->pending_update != 0)
  {
    return;
  }
  if (!this->state == PendingInit)
  {
    return;
  }
  if ((bool)(ProcessManager::CurrentTask == 2) ? 1 : 0)
  {
    this->pending_create = 0x01;
    return;
  }
  LinkedList_append(&ProcessManager::CreateTask, &this->process_link.update);
  return;
}
void Base::processCreate()
{
  u32 c0 = data_02085228[0];
  u32 c1 = data_02085228[1];
  u32 b0 = data_02085238[0];
  u32 b1 = data_02085238[1];
  u32 a0 = data_02085240[0];
  u32 a1 = data_02085240[1];

  this->func_01ffd524(
    c0,
    a0,
    a1,
    b0,
    c1,
    b1
  );
}
u32 Base::processDestroy()
{
  u16 object_id = this->object_id;

  u32 a1 = data_02085230[0];
  u32 a2 = data_02085230[1];
  u32 b1 = data_02085248[0];
  u32 b2 = data_02085248[1];
  u32 c1 = data_02085250[0];
  u32 c2 = data_02085250[1];
  u32 ret = this->func_01ffd524(
      a1,
      a2,
      b1,
      b2,
      c1,
      c2);
  if (ret == 1)
  {
    unloadSceneOverlay(object_id);
  }
  return ret;
}
bool Base::hasChildPendingCreation()
{
  SceneNode *connect = &this->process_link.connect;
  SceneNode *next = connect->func_020439f0();
  SceneNode *cur = connect->firstChild;

  while (!(cur == (SceneNode *)0x0 || cur == next))
  {
    if (
        (u8)((*cur->object).state == PendingInit) != 0)
    {
      return true;
    }
    cur = cur->func_02043a2c();
  };

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
  // TODO: What should be using r1 here?
  if (ret == (Base *)0x00)
  {
    data_0208fae8 = 0;
    data_0208faf0 = 0xFFFF;
    return (Base *)0x0;
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
void Base::unloadSceneOverlay(u16 a)
{
  if (data_0208fb00 != 0x00)
  {
    ((void (*)(u16))data_0208fb00)(a);
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
