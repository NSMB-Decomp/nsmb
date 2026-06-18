#include "BootScene.hpp"

BootScene::BootScene()
{
}
void *BootScene::create()
{
	return new BootScene();
}

s32 BootScene::onCreate()
{

	return true;
}

s32 BootScene::onDestroy()
{
	return true;
}

void BootScene::pendingDestroy()
{
}

s32 BootScene::onRender()
{
	return true;
}

s32 BootScene::onUpdate()
{
}

BootScene::~BootScene()
{
}
