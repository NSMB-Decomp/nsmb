#include "Object186.hpp"

void *Object186::create()
{
	return new Object186();
}

// 0x021821a0
ActorProfile Object186_Profile = { Object186::create, 186, 231, NULL /* TODO: 0x0217f354 */ };
