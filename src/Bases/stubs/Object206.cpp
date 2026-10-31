#include "Object206.hpp"

void *Object206::create()
{
	return new Object206();
}

void (Object206::*data_ov054_02171768)() = &Object206::func_ov054_02156890;

// 0x0216d3b4
ActorProfile Object206_Profile = { Object206::create, 206, 120, NULL };
