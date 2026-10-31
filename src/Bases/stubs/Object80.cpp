#include "Object80.hpp"

void *Object80::create()
{
	return new Object80();
}

void (Object80::*data_ov054_02171728)() = &Object80::func_ov054_02154090;
void (Object80::*data_ov054_02171738)() = &Object80::func_ov054_02153ff8;
void (Object80::*data_ov054_02171730)() = &Object80::func_ov054_02153db4;

// 0x0216cec8
ActorProfile Object80_Profile = { Object80::create, 80, 95, NULL };
