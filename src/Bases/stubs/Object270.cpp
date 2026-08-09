#include "Object270.hpp"

void *Object270::create()
{
	return new Object270();
}

// 0x021246c8
ActorProfile Object270_Profile = { Object270::create, 270, 278, NULL };
