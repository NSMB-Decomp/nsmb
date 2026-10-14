#include "Object232.hpp"

void *Object232::create()
{
	return new Object232();
}

// 0x02189718
ActorProfile Object232_Profile = { Object232::create, 232, 195, NULL /* TODO: 0x02187cf8 */ };
