#include "StageScene.hpp"

ObjectProfile StageScene_Profile = {StageScene::create,0x3, 0xA};

void* StageScene::create() {
    return new StageScene();
}

StageScene::StageScene() {}
