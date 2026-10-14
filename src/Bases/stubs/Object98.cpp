#include "Object98.hpp"

void *Object98::create()
{
	return new Object98();
}

// 0x0213ebf0
ActorProfile Object98_Profile = { Object98::create, 98, 232, NULL /* TODO: 0x0213dba8 */ };
