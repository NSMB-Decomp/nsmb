#include "GameOverScene.hpp"

void *GameOverScene::create()
{
	return new GameOverScene();
}

GameOverScene::GameOverScene()
{

}

// 0x020cccc0
ObjectProfile GameOverScene_Profile = { GameOverScene::create, 14, 21 };
