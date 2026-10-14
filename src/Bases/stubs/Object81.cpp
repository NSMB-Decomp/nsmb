#include "Object81.hpp"

void *Object81::create()
{
	return new Object81();
}

// 0x02143af0
ActorProfile Object81_Profile = { Object81::create, 81, 102, NULL /* TODO: 0x021424c4 */ };
