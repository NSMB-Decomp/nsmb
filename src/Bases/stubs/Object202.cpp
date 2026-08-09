#include "Object202.hpp"

void *Object202::create()
{
	return new Object202();
}

// 0x02127478
ActorProfile Object202_Profile = { Object202::create, 202, 249, NULL /* TODO: 0x020f833c */ };
