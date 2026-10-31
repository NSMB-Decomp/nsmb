#include "Object67.hpp"

void *Object67::create()
{
	return new Object67();
}

void (Object67::*data_ov054_02171740)() = &Object67::func_ov054_02154b44;
void (Object67::*data_ov054_02171748)() = &Object67::func_ov054_02154918;

// 0x0216d01c
ActorProfile Object67_Profile = { Object67::create, 67, 159, NULL /* TODO: 0x02154e60 */ };
