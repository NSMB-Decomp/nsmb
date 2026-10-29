#include "FireSnake.hpp"

extern "C" void func_ov023_0213e58c();

FireSnake::FireSnake()
{
}

s32 FireSnake::onCreate()
{
}

s32 FireSnake::onDestroy()
{
	func_ov023_0213e58c();
	return true;
}

void *FireSnake::create()
{
	return new FireSnake();
}
void *FireSnake::create_unused()
{
	return new FireSnake();
}

bool FireSnake::loadResources() {
	FS::Cache::loadFile(0x4fe, 0x0);
	FS::Cache::loadFile(0x4ff, 0x0);
	FS::Cache::loadFile(0x4fc, 0x0);
	FS::Cache::loadFile(0x4fd, 0x0);
	return true;
}
