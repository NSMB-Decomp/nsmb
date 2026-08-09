#include "Object150.hpp"

void *Object150::create()
{
	return new Object150();
}
bool Object150::onHeapCreated() {}
s32 Object150::Object150::onCreate() {}
bool Object150::onUpdate_0() {}
s32 Object150::onRender() {}
void Object150::pendingDestroy() {}
s32 Object150::onDestroy() {}

// 0x02173680
ActorProfile Object150_Profile = { Object150::create, 150, 174, NULL /* TODO: 0x02172b18 */ };
