#include "Object330.hpp"

void *Object330::create()
{
	return new Object330();
}

// 0x02138f90
ActorProfile Object330_Profile = { Object330::create, 330, 330, NULL };
