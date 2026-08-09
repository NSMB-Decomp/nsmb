#include "Object150.hpp"

void *Object150::create()
{
	return new Object150();
}

// 0x02173680
ActorProfile Object150_Profile = { Object150::create, 150, 174, NULL /* TODO: 0x02172b18 */ };
