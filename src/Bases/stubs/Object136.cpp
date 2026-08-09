#include "Object136.hpp"

void *Object136::create()
{
	return new Object136();
}

// 0x021483b0
ActorProfile Object136_Profile = { Object136::create, 136, 154, NULL /* TODO: 0x0214822c */ };
