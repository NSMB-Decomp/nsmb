#include "Object104.hpp"
#include "../../ProcessManager.hpp"
#include "Object103.hpp"

void *Object104::create()
{
	return new Object104();
}

// 0x0218e1f0
ActorProfile Object104_Profile = {Object104::create, 104, 225, NULL};

s32 Object104::onCreate()
{
	this->_3f3 = READ_NIBBLE(this->settings, 0);
	this->visible = false;
	return 1;
}

bool Object104::onUpdate_0()
{
	u32 uVar1;

	u32 uVar2 = func_ov000_020a6d18(this->position.x, this->position.y) & 0x10000;
	if (uVar2 != 0) {
		Object103 *object = (Object103*)ProcessManager::getNextObjectByObjectID(0x67, NULL);
		while (object != NULL) {
			if (this->_3f3 == object->_4a8) {
				object->_4a9 = 1;
				this->destroy(false);
				return true;
			}

			object = (Object103*)ProcessManager::getNextObjectByObjectID(0x67, object);
		}
	}
	this->destroyInactive(0);
	return true;
}

void Object104::pendingDestroy()
{
}

s32 Object104::onDestroy()
{
	return 1;
}