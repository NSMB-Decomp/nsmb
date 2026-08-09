#include "Object239.hpp"

void *Object239::create()
{
	return new Object239();
}

// 0x021330e8
ActorProfile Object239_Profile = { Object239::create, 239, 30, NULL /* TODO: 0x02132e4c */ };
