#include "Object311.hpp"

void *Object311::create()
{
	return new Object311();
}

void (Object311::*data_ov009_020dc188[3])() = {
    &Object311::func_ov009_020d8a40,
    &Object311::func_ov009_020d89c4,
    &Object311::func_ov009_020d89c0,
};

// 0x020db04c
ActorProfile Object311_Profile = { Object311::create, 311, 302, NULL /* TODO: 0x020d8978 */ };
