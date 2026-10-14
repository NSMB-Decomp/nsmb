#include "Object212.hpp"

void *Object212::create()
{
	return new Object212();
}

// 0x0218f168
ActorProfile Object212_Profile = { Object212::create, 212, 258, NULL /* TODO: 0x0218ee3c */ };
