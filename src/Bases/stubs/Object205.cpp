#include "Object205.hpp"

void *Object205::create()
{
	return new Object205();
}

// 0x02174990
ActorProfile Object205_Profile = { Object205::create, 205, 252, NULL /* TODO: 0x02174670 */ };
