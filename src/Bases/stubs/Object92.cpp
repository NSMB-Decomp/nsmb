#include "Object92.hpp"

void *Object92::create()
{
	return new Object92();
}

void (Object92::*data_ov054_02171770)() = &Object92::func_ov054_02156f44;

// 0x0216d4dc
ActorProfile Object92_Profile = { Object92::create, 92, 119, NULL };
