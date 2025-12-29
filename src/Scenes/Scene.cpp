#include "Scene.hpp"

Scene::Scene()
{
    this->skipFlags |= 1;
    this->skipFlags |= 4;
    Stage::actorFreezeFlag = 0;
    data_ov000_020ca84c = 0;
    data_02088f34 = 0;
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