#include "KeyScene.hpp"

void *KeyScene::create()
{
	return new KeyScene();
}

// 0x020cc620
ObjectProfile Object17_Profile = { KeyScene::create, 17, 24 };
