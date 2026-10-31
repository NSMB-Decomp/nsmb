#include "Object237.hpp"

void *Object237::create()
{
	return new Object237();
}

void (Object237::*data_ov054_02171750)() = &Object237::func_ov054_021556c4;
void (Object237::*data_ov054_02171758)() = &Object237::func_ov054_02155520;

// 0x0216d154
ActorProfile Object237_Profile = { Object237::create, 237, 50, NULL /* TODO: 0x02155e80 */ };
