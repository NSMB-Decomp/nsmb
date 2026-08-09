#include "Object75.hpp"

void *Object75::create()
{
	return new Object75();
}

void *Object76::create()
{
	return new Object76();
}

// 0x0217c1c0
ActorProfile Object75_Profile = { Object75::create, 75, 87, NULL /* TODO: 0x0217ba74 */ };

// 0x0217c1cc
ActorProfile Object76_Profile = { Object76::create, 76, 88, NULL /* TODO: 0x0217ba74 */ };
