#include "Object182.hpp"

void *Object182::create()
{
	return new Object182();
}

// 0x02132364
ActorProfile Object182_Profile = { Object182::create, 182, 221, NULL /* TODO: 0x020db4c0 */ };
