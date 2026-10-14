#include "Object41.hpp"

void *Object41::create()
{
	return new Object41();
}

void *Object42::create()
{
	return new Object42();
}

// 0x02179378
ActorProfile Object41_Profile = { Object41::create, 41, 55, NULL /* TODO: 0x02177468 */ };

// 0x02179384
ActorProfile Object42_Profile = { Object42::create, 42, 56, NULL /* TODO: 0x02177484 */ };
