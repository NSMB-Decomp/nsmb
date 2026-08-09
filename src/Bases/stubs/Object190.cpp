#include "Object190.hpp"

void *Object190::create()
{
	return new Object190();
}

// 0x02184ed8
ActorProfile Object190_Profile = { Object190::create, 190, 236, NULL /* TODO: 0x02180f0c */ };
