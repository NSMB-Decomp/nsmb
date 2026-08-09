#include "Object125.hpp"

void *Object125::create()
{
	return new Object125();
}

// 0x0218dee0
ActorProfile Object125_Profile = { Object125::create, 125, 182, NULL /* TODO: 0x0218c88c */ };
