#include "BootScene.hpp"

BootScene::BootScene() {}
void * BootScene::operator new(u32 a) {
    return new BootScene();
}