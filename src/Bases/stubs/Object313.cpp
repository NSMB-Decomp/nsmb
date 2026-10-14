#include "Object313.hpp"

void *Object313::create()
{
	return new Object313();
}

Object313::Object313() {
	this->_1c8 = 0;
}

// 0x020db134
ActorProfile Object313_Profile = { Object313::create, 313, 304, NULL /* TODO: 0x020d929c */ };
