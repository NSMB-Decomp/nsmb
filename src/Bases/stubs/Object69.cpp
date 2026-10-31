#include "Object69.hpp"

void *Object69::create()
{
	return new Object69();
}

void (Object69::*data_ov054_0217189c)() = &Object69::func_ov054_0215d7f0;

// 0x0216e16c
ActorProfile Object69_Profile = { Object69::create, 69, 81, NULL /* TODO: 0x0215e2c4 */ };
