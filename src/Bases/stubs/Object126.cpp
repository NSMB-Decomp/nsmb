#include "Object126.hpp"

void *Object126::create()
{
	return new Object126();
}

// 0x0217c684
ActorProfile Object126_Profile = { Object126::create, 126, 145, NULL /* TODO: 0x0217c2d4 */ };
