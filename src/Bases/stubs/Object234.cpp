#include "Object234.hpp"

void *Object234::create()
{
	return new Object234();
}

// 0x02187468
ActorProfile Object234_Profile = { Object234::create, 234, 197, NULL /* TODO: 0x02185dec */ };
