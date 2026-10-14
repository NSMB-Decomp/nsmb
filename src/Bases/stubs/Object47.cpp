#include "Object47.hpp"

void *Object47::create()
{
	return new Object47();
}

void *Object47::create2()
{
	return new Object47();
}

// 0x02189780
ActorProfile Object48_Profile = { Object47::create2, 48, 62, NULL /* TODO: 0x02188a68 */ };

// 0x0218978c
ActorProfile Object47_Profile = { Object47::create, 47, 61, NULL /* TODO: 0x02188a68 */ };
