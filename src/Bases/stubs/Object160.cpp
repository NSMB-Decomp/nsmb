#include "Object160.hpp"

void *Object160::create()
{
	return new Object160();
}

s32 Object160::onCreate() {}
s32 Object160::onDestroy() {}
s32 Object160::onUpdate() {}
s32 Object160::onRender() {}

Object160_Unknown::Object160_Unknown() {}

Object160::Object160() {

}

// 0x0216e2b0
ObjectProfile Object160_Profile = { Object160::create, 160, 6 };
