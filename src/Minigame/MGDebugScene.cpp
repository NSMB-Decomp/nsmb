#include "MGDebugScene.hpp"

bool MGDebugScene::preCreate()
{
	MGScene::preCreate();
}

bool MGDebugScene::preUpdate()
{
	bool a = MGScene::preUpdate();
	if (a != 0) {
		this->func_ov130_02126fc8();
		this->func_ov130_021271d0();
		return true;
	}
	return false;
}
