#include "EndingScene.hpp"

void *EndingScene::create()
{
	return new EndingScene();
}

// 0x020e9b88
ObjectProfile Object12_Profile = { EndingScene::create, 12, 19 };
