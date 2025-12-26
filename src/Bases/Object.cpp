#include "Object.hpp"

void Object::postCreate(u32 a)
{
    if (a == 1)
    {
        Object::destroy();
    }
    Base::postCreate(a);
}


Object* Object::spawnObject(u32 a, u32 b, u32 c)
{
  Object *child = (Object*)this->spawnChild(a,b,c);
  if (child->pending_destroy != false) {
    child = (Object *)0x0;
  }
  return child;
}

Scene* Object::spawnScene(u32 a, u32 b, u32 c)
{  
  Scene* scene = (Scene*)Base::spawnParent(a,b,c);
  if (scene->pending_destroy != false) {
    scene = (Scene *)0x0;
  }
  return scene;
}

void Object::__stub() {}
