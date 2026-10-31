#include "Object63.hpp"

void *Object63::create()
{
	return new Object63();
}

void (Object63::*data_ov080_0217db10)() = &Object63::func_ov080_0217bad0;

// 0x0217d810
ActorProfile Object63_Profile = { Object63::create, 63, 77, NULL /* TODO: 0x0217bf9c */ };
