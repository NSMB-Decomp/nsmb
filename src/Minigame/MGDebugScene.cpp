#include "MGDebugScene.hpp"

bool MGDebugScene::preCreate() {
    MGScene::preCreate();
}

bool MGDebugScene::preUpdate() {
    bool a = MGScene::preUpdate();
    if (a != 0) {

        return true;
    }
    return false;
}