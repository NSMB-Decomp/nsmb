#include "FireSnake.hpp"

FireSnake::FireSnake()
{
}

s32 FireSnake::onCreate()
{
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
