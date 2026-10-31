#include "Object120.hpp"

void *Object120::create()
{
	return new Object120();
}

void (Object120::*data_ov108_0218b020)() = &Object120::func_ov108_0218a5ec;
void (Object120::*data_ov108_0218b048)() = &Object120::func_ov108_0218a524;
void (Object120::*data_ov108_0218b040)() = &Object120::func_ov108_0218a278;
void (Object120::*data_ov108_0218b038)() = &Object120::func_ov108_0218a150;
void (Object120::*data_ov108_0218b030)() = &Object120::func_ov108_02189ec0;
void (Object120::*data_ov108_0218b028)() = &Object120::func_ov108_02189de0;

// 0x0218aef0
ActorProfile Object120_Profile = { Object120::create, 120, 139, NULL /* TODO: 0x0218ad40 */ };
