#include "Object71.hpp"

void *Object71::create()
{
	return new Object71();
}

void (Object71::*data_ov054_0217261c)() = &Object71::func_ov054_0216732c;

// 0x02170538
ActorProfile Object71_Profile = { Object71::create, 71, 83, NULL };
