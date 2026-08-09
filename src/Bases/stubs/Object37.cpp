#include "Object37.hpp"

void *Object37::create()
{
	return new Object37();
}

void *Object38::create()
{
	return new Object38();
}

// 0x0213f6d0
ActorProfile Object37_Profile = { Object37::create, 37, 51, NULL /* TODO: 0x0213e364 */ };

// 0x0213f6dc
ActorProfile Object38_Profile = { Object38::create, 38, 52, NULL /* TODO: 0x0213e364 */ };
