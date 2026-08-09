#include "Object204.hpp"

void *Object204::create()
{
	return new Object204();
}

// 0x02174718
ActorProfile Object204_Profile = { Object204::create, 204, 251, NULL /* TODO: 0x02173780 */ };
