#include "Object260.hpp"

void *Object260::create()
{
	return new Object260();
}

// 0x0216dec4
ActorProfile Object260_Profile = { Object260::create, 260, 260, NULL /* TODO: 0x0215b69c */ };
