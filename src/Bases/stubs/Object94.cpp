#include "Object94.hpp"

void *Object94::create()
{
	return new Object94();
}

void *Object95::create()
{
	return new Object95();
}

// 0x021261b4
ActorProfile Object94_Profile = { Object94::create, 94, 163, NULL /* TODO: 0x020df358 */ };

// 0x021261c0
ActorProfile Object95_Profile = { Object95::create, 95, 164, NULL /* TODO: 0x020df358 */ };
