#include "MGScene.hpp"

extern u8 data_0208b178;
extern u32 data_02139700;
extern u8 data_0203d2ac;
extern u32 data_0208b658;
extern u8 data_020887e0;
extern "C" void func_02122ba8(u32*);
extern "C" void func_021229d4();
extern "C" void func_0200e61c();
extern "C" void func_0200e944(u32, u32, u32);

#pragma thumb on

MGScene::MGScene()
{
	this->skipFlags |= 1;
	this->skipFlags |= 4;
}

bool MGScene::preCreate()
{
	if (!this->func_02024e50())
		return false;
	func_02024e94();
	this->_5c = 0x3ff;
	this->_60 = 0xf;
	return true;
}

void MGScene::postCreate(u32 a)
{
	func_0200e944(this->_5c, this->_60, 0);
	Object::postCreate(a);
}

bool MGScene::preDestroy()
{
	if (!Base::preDestroy()) {
		return false;
	}
	if (data_0208b178) {
		func_02122ba8(&data_02139700);
	}
	return true;
}
void MGScene::postDestroy(u32 a)
{
	if (a == 2) {
		data_0203d2ac = 0;
	}
	if (this->object_id == 0x146) {
		func_02024ad0(&data_0208b658);
	}
	if (data_020887e0 != 0) {
		func_021229d4();
		func_0200e61c();
	}
	Base::postDestroy(a);
}
bool MGScene::preUpdate()
{
}
void MGScene::postUpdate(u32)
{
}
bool MGScene::preRender()
{
}
void MGScene::postRender(u32)
{
}

#pragma thumb off
