#include "Object62.hpp"

void *Object62::create()
{
	return new Object62();
}

void (Object62::*data_ov054_02171780)() = &Object62::func_ov054_02157580;
void (Object62::*data_ov054_02171778)() = &Object62::func_ov054_021573f0;

// 0x0216d60c
ActorProfile Object62_Profile = { Object62::create, 62, 76, NULL /* TODO: 0x02157a08 */ };
