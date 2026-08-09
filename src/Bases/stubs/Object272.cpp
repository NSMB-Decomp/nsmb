#include "Object272.hpp"

void *Object272::create()
{
	return new Object272();
}

// 0x02124800
ActorProfile Object272_Profile = { Object272::create, 272, 280, NULL };
