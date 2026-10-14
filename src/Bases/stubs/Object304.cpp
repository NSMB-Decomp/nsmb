#include "Object304.hpp"

void *Object304::create()
{
	return new Object304();
}

Object304::Object304() {}

s32 Object304::onCreate() {}
s32 Object304::onDestroy() {}
s32 Object304::onUpdate() {}
s32 Object304::onRender() {}

// 0x0215c67c
ObjectProfile Object304_Profile = { Object304::create, 304, 5 };
