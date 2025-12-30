#include "Scene_8.hpp"


Scene_8::Scene_8() {};
void* Scene_8::create() {
    return new Scene_8();
}

bool Scene_8::onCreate() {};

bool Scene_8::onDestroy() {};

void Scene_8::pendingDestroy() {

}

bool Scene_8::onRender() {
    return true;
};

bool Scene_8::onUpdate() {};


Scene_8::~Scene_8() {
    
};