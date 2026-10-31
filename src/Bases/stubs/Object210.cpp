#include "Object210.hpp"

void *Object210::create()
{
	return new Object210();
}

void (Object210::*data_ov118_021901bc[4])() = {
    &Object210::func_ov118_0218eb98,
    &Object210::func_ov118_0218ea2c,
    &Object210::func_ov118_0218e698,
    &Object210::func_ov118_0218ea2c,
};
void (Object210::*data_ov118_0219019c[4])() = {
    &Object210::func_ov118_0218ea78,
    &Object210::func_ov118_0218e6a8,
    &Object210::func_ov118_0218e544,
    &Object210::func_ov118_0218e6a8,
};

// 0x0218feec
ActorProfile Object210_Profile = { Object210::create, 210, 256, NULL /* TODO: 0x0218e264 */ };
