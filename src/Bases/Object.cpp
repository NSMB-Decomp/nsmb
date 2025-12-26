#include "Object.hpp"

void Object::postCreate(u32 a)
{
    if (a == 1)
    {
        Object::destroy();
    }
    Base::postCreate(a);
}


Object* Object::spawnObject(u16 a, Base* b, u32 c, u8 d)
{
  Object *child = (Object*)Base::spawnChild(a,b,c,d);
  if (child->pending_destroy != false) {
    child = (Object *)0x0;
  }
  return child;
}

Object* Object::spawnScene(u16 a, u32 b, u8 c)
{  
  Object* scene = (Object*)Base::spawnParent(a,b,c);
  if (scene->pending_destroy != false) {
    scene = (Object *)0x0;
  }
  return scene;
}

void Object::__stub() {}
