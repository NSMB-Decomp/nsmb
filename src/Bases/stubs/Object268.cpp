#include "Object268.hpp"

void *Object268::create()
{
	return new Object268();
}

void (Object268::*data_ov010_0212acdc)() = &Object268::func_ov010_020f5a10;

// 0x021271dc
ActorProfile Object268_Profile = { Object268::create, 268, 157, NULL };
