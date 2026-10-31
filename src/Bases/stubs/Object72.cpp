#include "Object72.hpp"

void *Object72::create()
{
	return new Object72();
}

void (Object72::*data_ov054_02172624)() = &Object72::func_ov054_02167900;

// 0x0217067c
ActorProfile Object72_Profile = { Object72::create, 72, 84, NULL };
