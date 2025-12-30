#include "MGScene.hpp"

#pragma thumb on

MGScene::MGScene() {
    this->skipFlags |= 1;
    this->skipFlags |= 4;
}

bool MGScene::preCreate() {
    return true;
}

void MGScene::postCreate(u32) {
}

bool MGScene::preDestroy() {}
void MGScene::postDestroy(u32) {}
bool MGScene::preUpdate() {}
void MGScene::postUpdate() {}
bool MGScene::preRender() {}
void MGScene::postRender() {}

#pragma thumb off