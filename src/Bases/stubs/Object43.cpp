#include "Object43.hpp"

void *Object43::create()
{
	return new Object43();
}

void (Object43::*data_ov019_02137580[8])() = {
    &Object43::func_ov019_0213454c,
    &Object43::func_ov019_02134480,
    &Object43::func_ov019_02134320,
    &Object43::func_ov019_02133ccc,
    &Object43::func_ov019_02133924,
    &Object43::func_ov019_0213386c,
    &Object43::func_ov019_02133510,
    &Object43::func_ov019_021332ec,
};

// 0x02137458
ActorProfile Object43_Profile = { Object43::create, 43, 57, NULL /* TODO: 0x02135160 */ };
