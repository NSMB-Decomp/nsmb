#include "BootScene.hpp"

BootScene::BootScene() {}
void * BootScene::operator new(u32 a) {
    return new BootScene();
}

bool BootScene::onCreate() {

    return true;
}

bool BootScene::onDestroy() {
    return true;
}

void BootScene::pendingDestroy() {
    
}

bool BootScene::onRender() {
    return true;
}

bool BootScene::onUpdate() {

}

BootScene::~BootScene() {}
