#include "SaveScene.hpp"

void *SaveScene::create()
{
	return new SaveScene();
}

// 0x020e5820
ObjectProfile Object7_Profile = { SaveScene::create, 7, 15 };
