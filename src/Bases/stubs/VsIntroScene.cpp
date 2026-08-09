#include "VsIntroScene.hpp"

void *VsIntroScene::create()
{
	return new VsIntroScene();
}

// 0x0215b5c0
ObjectProfile Object15_Profile = { VsIntroScene::create, 15, 22 };
