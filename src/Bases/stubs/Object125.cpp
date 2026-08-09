#include "Object125.hpp"

const u8 data_ov117_0218de90[4] = {0x00, 0x10, 0x20, 0x30};
const u8 data_ov117_0218de94[4] = {0 ,4, 2, 6};
extern void* data_ov053_0216fc30[8];

void *Object125::create()
{
	return new Object125();
}

bool Object125::func_ov117_0218c9b0(u32 a)
{
	if (this->_3f4 == NULL) {
		return true;
	} else {
	 	return (this->**_3f4)(a);
	}
}
s32 Object125::onCreate()
{
	this->_404 = data_ov117_0218de90[(u8)(this->settings >> 0x1c & 3)];
	this->activeSize.set(0x100, 0x60);
	this->viewOffset.set(0, 0x10);
	this->renderSize.set(0, 0);
	return true;
}
bool Object125::onUpdate_0()
{
	this->func_ov117_0218c9b0(0);
	this->destroyInactive(0);
	return true;
}
s32 Object125::onRender()
{
	drawSprite(
		(u32)data_ov053_0216fc30[data_ov117_0218de94[this->settings >> 0x18 & 7]],
		this->position.x,
		this->position.y,
		this->_404, 
		0, 
		3, 
		&Vec2_32(0x1000, 0x1000), 
		this->_406,
		0, 
		0
	);

	return true;
}
bool Object125::loadResources()
{
	func_0200b83c(0x18);
	return true;
}
void Object125::pendingDestroy()
{
}
s32 Object125::onDestroy()
{
	return true;
}

// 0x0218dee0
ActorProfile Object125_Profile = {Object125::create, 125, 182, Object125::loadResources};
