#include "Object324.hpp"

void *Object324::create()
{
	return new Object324();
}

void (Object324::*data_ov008_020ee890)() = &Object324::func_ov008_020de404;
void (Object324::*data_ov008_020ee888)() = &Object324::func_ov008_020de348;

// 0x020e9bf0
ActorProfile Object324_Profile = { Object324::create, 324, 4, NULL };
