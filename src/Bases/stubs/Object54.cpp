#include "Object54.hpp"

void *Object54::create()
{
	return new Object54();
}

// 0x02179180
ActorProfile Object54_Profile = { Object54::create, 54, 68, NULL /* TODO: 0x02176780 */ };
