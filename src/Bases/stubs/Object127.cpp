#include "Object127.hpp"

void *Object127::create()
{
	return new Object127();
}

// 0x02179880
ActorProfile Object127_Profile = { Object127::create, 127, 184, NULL /* TODO: 0x0217905c */ };
