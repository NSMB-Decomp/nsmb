#include "Object317.hpp"

void *Object317::create()
{
	return new Object317();
}

s32 Object317::onCreate()
{
	if (this->prepareResourcesSafe(0, Memory_gameHeap)) {
		this->position.x = 0;
		this->position.y = 0;
		this->position.z = 0;
		this->rotation.x = 0;
		this->rotation.y = 0;
		this->rotation.z = 0;
		this->scale.x = 0x1000;
		this->scale.y = 0x1000;
		this->scale.z = 0x1000;
		this->_5b4 = 0x30000;
		this->_5b8 = 0;
		this->_5bb = 0;
		this->func_ov008_020cd520();
		return 1;
	} else {
		return 0;
	}
}

// 0x020e59a8
ActorProfile Object317_Profile = {Object317::create, 317, 292, NULL /* TODO: 0x020cd478 */};
