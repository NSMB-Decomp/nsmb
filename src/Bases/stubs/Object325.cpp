#include "Object325.hpp"

void *Object325::create()
{
	return new Object325();
}

// 0x02123d58
ActorProfile Object325_Profile = { Object325::create, 325, 307, NULL };
