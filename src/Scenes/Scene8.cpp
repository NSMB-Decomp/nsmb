#include "Scene8.hpp"

Scene8::Scene8() {};
void *Scene8::create()
{
	return new Scene8();
}

bool Scene8::onCreate() {};

bool Scene8::onDestroy() {};

void Scene8::pendingDestroy()
{
}

bool Scene8::onRender()
{
	return true;
};

bool Scene8::onUpdate() {};

Scene8::~Scene8() {

};
