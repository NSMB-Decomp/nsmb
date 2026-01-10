#include "Base_autoload.cpp"
#include "Nitro.hpp"

u32 data_02085224 = 1;

ProcessLink* func_02043b58(ProcessLink *);
Base::Base()
{
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
  this->settings = SpawnParam_Settings;
  this->object_id = SpawnParam_ObjectId;
  this->_12 = SpawnParam_Type;

  SceneGraph_addChild(&ProcessManager::ConnectTask, &this->process_link, SpawnParam_Parent);
  u32 id_index = ProcessManager::getIDIndex(&this->process_link);
  LinkedList_Prepend(&ProcessManager::idLookupProcesses[id_index], &this->process_link.idLookup);

  ObjectProfile *profile = CurrentProfileTable[this->object_id];
  
  u32 render_priority = profile->updatePriority;
  PriorityNode* render = &this->process_link.update;
  render->currentPriority = render_priority;
  render->sortPriority = render_priority;
  u32 update_priority = profile->renderPriority;
  PriorityNode* update = &this->process_link.render;
  update->currentPriority = update_priority;
  update->sortPriority = update_priority;

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
  LinkedList_Remove(&ProcessManager::CreateTask.linked_list, &this->process_link.update);
  if ((BOOL)(ProcessManager::CurrentTask == Execute) != FALSE)
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
          (this->_54 == 0 || func_0204d82c()) &&
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
  LinkedList_Remove(&ProcessManager::DestroyTask.linked_list, &this->process_link.update);
  if (this->heap != NULL)
  {
    func_02045128();
  }
  if (this->_54 != NULL)
  {
    func_0204d908();
  }
  this->~Base();
  func_02044ab0(this, data_0208b720);
}
void Base::pendingDestroy() {}
void Base::destroy()
{
  if (
    (this->pending_destroy == false) &&
    (BOOL)(this->state == Inactive) == FALSE)
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
bool Base::prepareResourcesSafe(u32 size, Heap* parent)
{
  Heap *user = (Heap*)NULL;
  void *z;
  Heap *heap;
  Heap *heap2;
  u32 user_remaining;
  u32 result;
  void* heap_ptr;

  if (this->heap != NULL)
  {
    return true;
  }
  if (
      size != 0 &&
      (user = FrameHeap::create(size, parent, 0x20), user != NULL))
  {
    heap_ptr = (void *)((u32)(user->start) & 0x10);
    if (heap_ptr != NULL)
    {
      user->allocate(0x10, 0x10);
    }
    heap = user->setCurrent();
    result = this->onHeapCreated();
    heap->setCurrent();
    if (
        heap_ptr == NULL &&
        (z = user->allocate(0x10, 0x10), z == NULL))
    {
      result = 0;
    }

    if (result == 0)
    {
      user->destroy();
      user = (Heap*)NULL;
    }
    else
    {
      u32 user_size = user->size;
      u32 max_user_size = user->maxAllocationUnitSize();
      user_remaining = (user_size - max_user_size) + 0x1f & ~0x1f;
            
      if (size == user_remaining) {
        user->resizeToFit();
        this->heap = user;
        return true;
      }
    
    }
  }

  if (user == NULL) {
    user = FrameHeap::create(~0, parent, 0x20);
    heap_ptr = (void *)((u32)(user->start) & 0x10);
    if (heap_ptr != NULL)
    {
      user->allocate(0x10, 0x10);
    }
    heap2 = user->setCurrent();
    result = this->onHeapCreated();
    heap2->setCurrent();
    if (
        heap_ptr == NULL &&
        (z = user->allocate(0x10, 0x10), z == NULL))
    {
      result = 0;
    }

    if (result == 0)
    {
      user->destroy();
      this->destroy();
      return false;
    }
      u32 user_size = user->size;
      u32 max_user_size = user->maxAllocationUnitSize();
      user_remaining = (user_size - max_user_size) + 0x1f & ~0x1f;
  }
  if (user != NULL) {
    u32 user_size = user->size;
    Heap* old_00= (Heap*)NULL;
    u32 max_user_size;

    max_user_size = user->maxAllocationUnitSize();
    u32 z = (user_size - max_user_size);
    u32 y = parent->maxAllocationUnitSize();
    z = ((z + 0xf & ~0xf) + 0x30);

    if (z < y) {
      old_00 = FrameHeap::create(user_remaining,parent,0x20);
    }

    if (old_00 != NULL) {
      if (old_00 < user) {
        user->destroy();
        user = (Heap*)NULL;
        heap2 = old_00->setCurrent();
        result = this->onHeapCreated();
        heap2->setCurrent();
        if (!result) {
          old_00->destroy();
          old_00 = (Heap*)NULL;
        }
      } else {
          old_00->destroy();
          old_00 = (Heap*)NULL;
      }
    }

    if (old_00 != NULL) {
      old_00->resizeToFit();
      this->heap = old_00;
      return true;
    }

    if (user != NULL) {
      user->resizeToFit();
      this->heap = user;
      return true;
    }
  }

  this->destroy();
  return false;
}
bool Base::prepareResourcesFast(u32 size, Heap* parent)
{
  Heap *user;
  Heap *heap;
  void *z;
  u32 result;
  void* heap_ptr;

  if (this->heap != NULL)
  {
    return true;
  }
  if (
      size != 0 &&
      (user = FrameHeap::create(size, parent, 0x20), user != NULL))
  {
    heap_ptr = (void *)((u32)(user->start) & 0x10);
    if (heap_ptr != NULL)
    {
      user->allocate(0x10, 0x10);
    }
    heap = user->setCurrent();
    result = this->onHeapCreated();
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
  if ((BOOL)(ProcessManager::CurrentTask == 2) != FALSE)
  {
    this->pending_create = 0x01;
    return;
  }
  LinkedList_append(&ProcessManager::CreateTask.linked_list, &this->process_link.update);
  return;
}
i32 Base::processCreate()
{
  bool (Base::*on)() = Base::onCreate;
  bool (Base::*pre)() = Base::preCreate;
  void (Base::*post)(u32) = Base::postCreate;
  return this->process(on,pre,post);
}

i32 Base::processDestroy()
{
  u16 object_id = this->object_id;
  bool (Base::*on)() = Base::onDestroy;
  bool (Base::*pre)() = Base::preDestroy;
  void (Base::*post)(u32) = Base::postDestroy;

  u32 ret = this->process(on,pre,post);
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
  SpawnParam_Settings = c;
  SpawnParam_ObjectId = a;
  SpawnParam_Type = d;
  SpawnParam_Parent = b;
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
  Base *ret = (Base*)(CurrentProfileTable)[overlay_id]->constructor();
  
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
Base *Base::spawnChild(u16 overlay_id, Base *parent, u32 c, u8 d)
{
  if (parent != (Base *)0x00)
  {
    return parent->spawn(overlay_id, &parent->process_link, c, d);
  }
  return (Base *)0x00;
}
Base *Base::spawnParent(u16 a, u32 b, u8 c)
{
  return Base::spawn(a, (ProcessLink*)NULL, b, c);
}
