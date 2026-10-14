#include "Object287.hpp"

// 0x020d7dd4
void *Object287_create()
{
	return new StageEffect();
}

// 0x020d7da8
void *Object288_create()
{
	return new StageEffect();
}

// 0x020d7d7c
void *Object289_create()
{
	return new StageEffect();
}

// 0x020d7d50
void *Object290_create()
{
	return new StageEffect();
}

// 0x020d7d24
void *Object291_create()
{
	return new StageEffect();
}

// 0x020d7cf8
void *Object292_create()
{
	return new StageEffect();
}

// 0x020d7ccc
void *Object293_create()
{
	return new StageEffect();
}

// 0x020d7ca0
void *Object294_create()
{
	return new StageEffect();
}

// 0x020d7c74
void *Object295_create()
{
	return new StageEffect();
}

// 0x020d7c48
void *Object296_create()
{
	return new StageEffect();
}

// 0x020d7c1c
void *Object297_create()
{
	return new StageEffect();
}

// 0x020d7bf0
void *Object298_create()
{
	return new StageEffect();
}

// 0x020d7bc4
void *Object299_create()
{
	return new StageEffect();
}

// 0x020d7b98
void *Object300_create()
{
	return new StageEffect();
}

// 0x020d7b74
bool Object287_loadResources()
{
	FS::Cache::loadFile(0x6e8, false);
	return true;
}

// 0x020d7b50
bool Object288_loadResources()
{
	FS::Cache::loadFile(0x6e7, false);
	return true;
}

// 0x020d7b2c
bool Object289_loadResources()
{
	FS::Cache::loadFile(0x6e9, false);
	return true;
}

// 0x020d7b08
bool Object290_loadResources()
{
	FS::Cache::loadFile(0x6ea, false);
	return true;
}

// 0x020d7ae4
bool Object291_loadResources()
{
	FS::Cache::loadFile(0x6eb, false);
	return true;
}

// 0x020d7ac0
bool Object292_loadResources()
{
	FS::Cache::loadFile(0x6ec, false);
	return true;
}

// 0x020d7a9c
bool Object293_loadResources()
{
	FS::Cache::loadFile(0x6ed, false);
	return true;
}

// 0x020d7a78
bool Object294_loadResources()
{
	FS::Cache::loadFile(0x6ee, false);
	return true;
}

// 0x020d7a54
bool Object295_loadResources()
{
	FS::Cache::loadFile(0x6ef, false);
	return true;
}

// 0x020d7a34
bool Object296_loadResources()
{
	FS::Cache::loadFile(0x6f0, false);
	return true;
}

// 0x020d7a10
bool Object297_loadResources()
{
	FS::Cache::loadFile(0x6f3, false);
	return true;
}

// 0x020d79ec
bool Object298_loadResources()
{
	FS::Cache::loadFile(0x6f4, false);
	return true;
}

// 0x020d79c8
bool Object299_loadResources()
{
	FS::Cache::loadFile(0x6f1, false);
	return true;
}

// 0x020d79a4
bool Object300_loadResources()
{
	FS::Cache::loadFile(0x6f2, false);
	return true;
}

// 0x020d7954
StageEffect::StageEffect()
{
}

// 0x02124e34
ActorProfile Object293_Profile = { Object293_create, 293, 318, Object293_loadResources };

// 0x02124e40
ActorProfile Object295_Profile = { Object295_create, 295, 320, Object295_loadResources };

// 0x02124e58
ActorProfile Object297_Profile = { Object297_create, 297, 322, Object297_loadResources };

// 0x02124e64
ActorProfile Object298_Profile = { Object298_create, 298, 323, Object298_loadResources };

// 0x02124e70
ActorProfile Object299_Profile = { Object299_create, 299, 324, Object299_loadResources };

// 0x02124e7c
ActorProfile Object292_Profile = { Object292_create, 292, 317, Object292_loadResources };

// 0x02124e88
ActorProfile Object300_Profile = { Object300_create, 300, 325, Object300_loadResources };

// 0x02124e94
ActorProfile Object287_Profile = { Object287_create, 287, 312, Object287_loadResources };

// 0x02124ea0
ActorProfile Object289_Profile = { Object289_create, 289, 314, Object289_loadResources };

// 0x02124eac
ActorProfile Object290_Profile = { Object290_create, 290, 315, Object290_loadResources };

// 0x02124eb8
ActorProfile Object296_Profile = { Object296_create, 296, 321, Object296_loadResources };

// 0x02124ec4
ActorProfile Object291_Profile = { Object291_create, 291, 316, Object291_loadResources };

// 0x02124ed0
ActorProfile Object294_Profile = { Object294_create, 294, 319, Object294_loadResources };

// 0x02124edc
ActorProfile Object288_Profile = { Object288_create, 288, 313, Object288_loadResources };
