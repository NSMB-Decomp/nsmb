#include "FireSnake.hpp"
#include <nsmb/file_ids.hpp>

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
	FS::Cache::loadFile(NSMB_FILE_ID_enemy_f_snake_nsbmd, 0x0);
	FS::Cache::loadFile(NSMB_FILE_ID_enemy_f_snake_nsbtp, 0x0);
	FS::Cache::loadFile(NSMB_FILE_ID_enemy_f_body_nsbmd, 0x0);
	FS::Cache::loadFile(NSMB_FILE_ID_enemy_f_body_nsbtp, 0x0);
	return true;
}
