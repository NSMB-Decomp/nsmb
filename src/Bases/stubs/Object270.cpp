#include "Object270.hpp"

void *Object270::create2()
{
	return new Object270();
}

void *Object270::create()
{
	return new Object270();
}

// 0x021246c8
ActorProfile Object270_Profile = { Object270::create, 270, 278, NULL };

// 0x021246d4
ActorProfile Object271_Profile = { Object270::create2, 271, 279, NULL };
