#include "Object266.hpp"

void *Object266::create()
{
	return new Object266();
}

// 0x02146ad8
ActorProfile Object266_Profile = { Object266::create, 266, 156, NULL };
