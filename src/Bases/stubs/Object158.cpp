#include "Object158.hpp"

void *Object158::create()
{
	return new Object158();
}

void *Object158::create2()
{
	return new Object158();
}

// 0x0216ff58
ActorProfile Object159_Profile = { Object158::create2, 159, 187, NULL /* TODO: 0x0216236c */ };

// 0x0216ff64
ActorProfile Object158_Profile = { Object158::create, 158, 186, NULL /* TODO: 0x0216236c */ };
