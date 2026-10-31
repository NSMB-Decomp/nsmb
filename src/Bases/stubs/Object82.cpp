#include "Object82.hpp"

void *Object82::create()
{
	return new Object82();
}

void (Object82::*data_ov111_0218a760)() = &Object82::func_ov111_0218a124;
void (Object82::*data_ov111_0218a770)() = &Object82::func_ov111_02189e98;
void (Object82::*data_ov111_0218a768)() = &Object82::func_ov111_02189df8;

// 0x0218a518
ActorProfile Object82_Profile = { Object82::create, 82, 104, NULL };
