#include "Object48.hpp"

void *Object48::create()
{
	return new Object48();
}

// 0x02189780
ActorProfile Object48_Profile = { Object48::create, 48, 62, NULL /* TODO: 0x02188a68 */ };
