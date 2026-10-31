#include "Object74.hpp"

void *Object74::create()
{
	return new Object74();
}

void (Object74::*data_ov078_0217b5e0)() = &Object74::func_ov078_0217a430;
void (Object74::*data_ov078_0217b5e8)() = &Object74::func_ov078_02179f74;

// 0x0217b390
ActorProfile Object74_Profile = { Object74::create, 74, 86, NULL /* TODO: 0x0217a9d8 */ };
