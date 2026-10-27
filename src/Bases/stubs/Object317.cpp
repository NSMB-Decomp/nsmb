#include "Object317.hpp"

u32 data_ov008_020e59b4[8] = {0x682, 0x683, 0x684, 0x685, 0x686, 0x687, 0x688, 0x689};

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

bool Object317::onHeapCreated()
{
	for (s32 i = 0; i < 8; i++) {
		void* bmd = FS::Cache::getFile(data_ov008_020e59b4[i]);
		BOOL a = this->models[i].create(bmd, 0, 0);
		if (a == FALSE) {
			return false;
		}
	}
	return true;
}

bool Object317::func_ov008_020cd478()
{
	for (s32 i = 0; i < 8; i++) {
		FS::Cache::loadFile(data_ov008_020e59b4[i], 0);
	}
	return true;
}

// 0x020e59a8
ActorProfile Object317_Profile = {Object317::create, 317, 292, NULL /* TODO: 0x020cd478 */};
