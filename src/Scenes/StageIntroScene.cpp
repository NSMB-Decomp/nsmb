#include "Scene.hpp"

class StageIntroScene : Scene {
	virtual s32 onUpdate();
	virtual s32 onRender();
	virtual void pendingDestroy();
	virtual s32 onDestroy();
	virtual s32 onCreate();
	~StageIntroScene();
	StageIntroScene();
};

StageIntroScene::StageIntroScene() {
	
}

StageIntroScene::~StageIntroScene() {

}

s32 StageIntroScene::onCreate() {

}

s32 StageIntroScene::onDestroy() {

}

void StageIntroScene::pendingDestroy() {

}

s32 StageIntroScene::onRender() {

}

s32 StageIntroScene::onUpdate() {

}
