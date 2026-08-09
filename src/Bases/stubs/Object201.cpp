#include "Object201.hpp"

void *Object201::create()
{
	return new Object201();
}

// 0x021734e0
ActorProfile Object201_Profile = { Object201::create, 201, 248, NULL /* TODO: 0x02173394 */ };
