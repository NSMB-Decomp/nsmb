#include "Object325.hpp"
extern void func_ov010_020e6524();
extern void func_01ffded0();

void *Object325::create()
{
	return new Object325();
}

s32 Object325::onRender() {
	func_ov010_020e6524();
	Nitro::func_01ff9010();
	return true;
}

s32 Object325::onUpdate() {
	func_01ffded0();
	return true;
}

// 0x02123d58
ActorProfile Object325_Profile = { Object325::create, 325, 307, NULL };
