#include "Object108.hpp"

void *Object108::create()
{
	return new Object108();
}

// 0x02177620
ActorProfile Object108_Profile = { Object108::create, 108, 124, NULL /* TODO: 0x02176e7c */ };
