#include "Object124.hpp"

void *Object124::create()
{
	return new Object124();
}

void (Object124::*data_ov110_0218a940)() = &Object124::func_ov110_02189f90;
void (Object124::*data_ov110_0218a958)() = &Object124::func_ov110_02189efc;
void (Object124::*data_ov110_0218a950)() = &Object124::func_ov110_02189e78;
void (Object124::*data_ov110_0218a948)() = &Object124::func_ov110_02189de0;

// 0x0218a800
ActorProfile Object124_Profile = { Object124::create, 124, 143, NULL /* TODO: 0x0218a678 */ };
