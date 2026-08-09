#include "Object128.hpp"

void *Object128::create()
{
	return new Object128();
}

// 0x02133a88
ActorProfile Object128_Profile = { Object128::create, 128, 146, NULL /* TODO: 0x021335d0 */ };
