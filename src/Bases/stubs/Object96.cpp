#include "Object96.hpp"

void *Object96::create()
{
	return new Object96();
}

// 0x02145200
ActorProfile Object96_Profile = { Object96::create, 96, 244, NULL /* TODO: 0x02142fa8 */ };
