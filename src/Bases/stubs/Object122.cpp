#include "Object122.hpp"

void *Object122::create()
{
	return new Object122();
}

// 0x02143c18
ActorProfile Object122_Profile = { Object122::create, 122, 141, NULL /* TODO: 0x0214397c */ };
