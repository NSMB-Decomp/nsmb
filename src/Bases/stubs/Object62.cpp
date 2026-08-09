#include "Object62.hpp"

void *Object62::create()
{
	return new Object62();
}

// 0x0216d60c
ActorProfile Object62_Profile = { Object62::create, 62, 76, NULL /* TODO: 0x02157a08 */ };
