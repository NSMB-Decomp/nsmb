#include "Object261.hpp"

void *Object261::create()
{
	return new Object261();
}

// 0x0216e044
ActorProfile Object261_Profile = { Object261::create, 261, 261, NULL /* TODO: 0x0215d148 */ };
