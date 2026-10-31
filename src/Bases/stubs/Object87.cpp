#include "Object87.hpp"

void *Object87::create()
{
	return new Object87();
}

void (Object87::*data_ov054_02171760)() = &Object87::func_ov054_02156124;

// 0x0216d284
ActorProfile Object87_Profile = { Object87::create, 87, 110, NULL };
