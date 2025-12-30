#include "StageScene.hpp"

ObjectProfile StageScene_Profile = {StageScene::operator new,0x3, 0xA};

void* StageScene::operator new(u32) {
    return new StageScene();
}


StageScene::StageScene() {}
