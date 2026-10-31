#include "Object86.hpp"

void *Object86::create()
{
	return new Object86();
}

void (Object86::*data_ov054_021717c8)() = &Object86::func_ov054_02159c94;
void (Object86::*data_ov054_021717c0)() = &Object86::func_ov054_02159ab8;
void (Object86::*data_ov054_021717b8)() = &Object86::func_ov054_021599a4;

// 0x0216dd40
ActorProfile Object86_Profile = { Object86::create, 86, 109, NULL };
