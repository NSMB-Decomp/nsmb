#include "KeyScene.hpp"

void *KeyScene::create()
{
	return new KeyScene();
}

s32 KeyScene::onCreate() {

}

s32 KeyScene::onDestroy() {
	return true;
}

s32 KeyScene::onRender() {
	return true;
}

void KeyScene::pendingDestroy() {

}

s32 KeyScene::onUpdate() {
	
}

KeyScene::~KeyScene() {

}

// 0x020cc620
ObjectProfile Object17_Profile = { KeyScene::create, 17, 24 };
