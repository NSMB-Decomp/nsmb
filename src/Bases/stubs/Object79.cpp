#include "Object79.hpp"

void *Object79::create()
{
	return new Object79();
}

void (Object79::*data_ov047_02148400[4])() = {
    &Object79::func_ov047_0214793c,
    &Object79::func_ov047_021478a0,
    &Object79::func_ov047_02147840,
    &Object79::func_ov047_02147488,
};

// 0x02148284
ActorProfile Object79_Profile = { Object79::create, 79, 94, NULL /* TODO: 0x02147454 */ };
