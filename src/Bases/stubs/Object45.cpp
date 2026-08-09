#include "Object45.hpp"

void *Object45::create()
{
	return new Object45();
}

// 0x02175750
ActorProfile Object45_Profile = { Object45::create, 45, 59, NULL /* TODO: 0x021753b8 */ };
