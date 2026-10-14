#include "Object112.hpp"

void *Object112::create()
{
	return new Object112();
}

// 0x02148548
ActorProfile Object112_Profile = { Object112::create, 112, 130, NULL /* TODO: 0x0214833c */ };
