#include "Object196.hpp"

void *Object196::create()
{
	return new Object196();
}

void (Object196::*data_ov107_0218a9a0[2])() = {
    &Object196::func_ov107_02189fe4,
    &Object196::func_ov107_02189d84,
};

// 0x0218a870
ActorProfile Object196_Profile = { Object196::create, 196, 242, NULL /* TODO: 0x02189c08 */ };
