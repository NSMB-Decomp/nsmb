#include "Scene.hpp"

Scene::Scene()
{
    this->skipFlags |= 1;
    this->skipFlags |= 4;
    //<conflict> _SceneRelated = (code)0x0;
    //inited1 = 0;
    //hasSceneSwitched = false;
}

Scene::~Scene()
{
}

bool Scene::preCreate()
{
    return true;
}

void Scene::postCreate(u32 a)
{
}