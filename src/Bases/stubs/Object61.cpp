#include "Object61.hpp"

void *Object61::create()
{
	return new Object61();
}

void (Object61::*data_ov078_0217b5f0)() = &Object61::func_ov078_0217ac18;

// 0x0217b4c0
ActorProfile Object61_Profile = { Object61::create, 61, 75, NULL /* TODO: 0x0217b1a4 */ };
