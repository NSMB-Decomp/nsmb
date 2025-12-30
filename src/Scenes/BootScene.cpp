#include "BootScene.hpp"

BootScene::BootScene() {}
BootScene::~BootScene() {}
void * BootScene::operator new(u32 a) {
    return new BootScene();
}