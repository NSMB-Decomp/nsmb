#include "Object306.hpp"

void *Object306::create()
{
	return new Object306();
}

void (Object306::*data_ov009_020dbf5c[8])() = {
    &Object306::func_ov009_020d570c,
    &Object306::func_ov009_020d5634,
    &Object306::func_ov009_020d55b0,
    &Object306::func_ov009_020d5578,
    &Object306::func_ov009_020d5504,
    &Object306::func_ov009_020d5480,
    &Object306::func_ov009_020d5424,
    &Object306::func_ov009_020d5390,
};

// 0x020dac58
ActorProfile Object306_Profile = { Object306::create, 306, 297, NULL /* TODO: 0x020d5330 */ };
