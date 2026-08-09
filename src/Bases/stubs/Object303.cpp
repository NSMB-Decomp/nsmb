#include "Object303.hpp"

void *Object303::create()
{
	return new Object303();
}

// 0x020c9388
ActorProfile Object303_Profile = { Object303::create, 303, 291, NULL };
