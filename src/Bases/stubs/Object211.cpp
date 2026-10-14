#include "Object211.hpp"

void *Object211::create()
{
	return new Object211();
}

// 0x0212704c
ActorProfile Object211_Profile = { Object211::create, 211, 257, NULL };
