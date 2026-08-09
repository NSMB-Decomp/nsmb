#include "Object188.hpp"

void *Object188::create()
{
	return new Object188();
}

// 0x02188970
ActorProfile Object188_Profile = { Object188::create, 188, 234, NULL /* TODO: 0x021875a8 */ };
