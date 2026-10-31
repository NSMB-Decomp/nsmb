#include "Object309.hpp"

void *Object309::create()
{
	return new Object309();
}

void (Object309::*data_ov009_020dc11c[9])() = {
    &Object309::func_ov009_020d7abc,
    &Object309::func_ov009_020d7a68,
    &Object309::func_ov009_020d7a1c,
    &Object309::func_ov009_020d79b0,
    &Object309::func_ov009_020d7964,
    &Object309::func_ov009_020d78f0,
    &Object309::func_ov009_020d7858,
    &Object309::func_ov009_020d77bc,
    &Object309::func_ov009_020d77a0,
};

// 0x020daf4c
ActorProfile Object309_Profile = { Object309::create, 309, 300, NULL /* TODO: 0x020d7740 */ };
