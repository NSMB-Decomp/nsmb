#include "Object77.hpp"

void *Object77::create()
{
	return new Object77();
}

void (Object77::*data_ov012_02132520)() = &Object77::func_ov012_02130d84;

// 0x021321ec
ActorProfile Object77_Profile = { Object77::create, 77, 89, NULL /* TODO: 0x02130e9c */ };
