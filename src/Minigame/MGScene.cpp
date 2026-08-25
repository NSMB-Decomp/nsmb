#include "MGScene.hpp"

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

void MGScene::postCreate(u32)
{
}

bool MGScene::preDestroy()
{
}
void MGScene::postDestroy(u32)
{
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
