#include "Object64.hpp"

void *Object64::create()
{
	return new Object64();
}

// 0x0213c548
ActorProfile Object64_Profile = { Object64::create, 64, 78, NULL /* TODO: 0x0213c45c */ };
