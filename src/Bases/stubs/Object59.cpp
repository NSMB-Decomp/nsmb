#include "Object59.hpp"

void *Object59::create()
{
	return new Object59();
}

void (Object59::*data_ov066_02178c20)() = &Object59::func_ov066_02175b64;

// 0x02178948
ActorProfile Object59_Profile = { Object59::create, 59, 73, NULL /* TODO: 0x02176008 */ };
