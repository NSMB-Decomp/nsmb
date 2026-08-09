#include "Object305.hpp"

void *Object305::create()
{
	return new Object305();
}

Object305::Object305() {
	this->_121 = 0;
}

// 0x020dabb4
ActorProfile Object305_Profile = { Object305::create, 305, 11, NULL /* TODO: 0x020d49dc */ };
