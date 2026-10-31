#include "Object307.hpp"

void *Object307::create()
{
	return new Object307();
}

void (Object307::*data_ov009_020dbf9c[4])() = {
    &Object307::func_ov009_020d5b48,
    &Object307::func_ov009_020d5ae0,
    &Object307::func_ov009_020d5a94,
    &Object307::func_ov009_020d5a40,
};

// 0x020dacdc
ActorProfile Object307_Profile = { Object307::create, 307, 298, NULL /* TODO: 0x020d59ec */ };
