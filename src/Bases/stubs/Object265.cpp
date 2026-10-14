#include "Object265.hpp"

void *Object265::create()
{
	return new Object265();
}

// 0x0213bd2c
ActorProfile Object265_Profile = { Object265::create, 265, 155, NULL };
