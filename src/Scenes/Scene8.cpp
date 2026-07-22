#include "Scene8.hpp"

Scene8::Scene8() {};
void *Scene8::create()
{
	return new Scene8();
}

s32 Scene8::onCreate() {};

i32 Scene8::onDestroy() {
	FS::Cache::clear();
	func_02011d40();
	return true;
}


void Scene8::pendingDestroy()
{
}

s32 Scene8::onRender()
{
	return true;
};

u16 data_02087650[2][2];
s32 Scene8::onUpdate()
{
	if ((u16)(data_02087650[Input::localConsoleID][0] & 0xc) == 0xc) {
		func_02011e3c(0x1e);
		func_020131fc(2, 0);
		return true;
	}
	return true;
};

Scene8::~Scene8() {

};
