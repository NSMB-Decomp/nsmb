#include "Object109.hpp"

void *Object109::create()
{
	return new Object109();
}

// 0x02177740
ActorProfile Object109_Profile = { Object109::create, 109, 125, NULL /* TODO: 0x021773cc */ };
