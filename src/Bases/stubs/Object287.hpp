#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// Foreground effects, id 287-300.

class StageEffect : public StageEntity {
public:
	u8 _pad0[0x90];
	StageEffect();
	~StageEffect() {};
};

// slot 300  profile @ 0x02124e88
void *Object300_create();
bool Object300_loadResources();
extern ActorProfile Object300_Profile;

// slot 299  profile @ 0x02124e70
void *Object299_create();
bool Object299_loadResources();
extern ActorProfile Object299_Profile;

// slot 298  profile @ 0x02124e64
void *Object298_create();
bool Object298_loadResources();
extern ActorProfile Object298_Profile;

// slot 297  profile @ 0x02124e58
void *Object297_create();
bool Object297_loadResources();
extern ActorProfile Object297_Profile;

// slot 296  profile @ 0x02124eb8
void *Object296_create();
bool Object296_loadResources();
extern ActorProfile Object296_Profile;

// slot 295  profile @ 0x02124e40
void *Object295_create();
bool Object295_loadResources();
extern ActorProfile Object295_Profile;

// slot 294  profile @ 0x02124ed0
void *Object294_create();
bool Object294_loadResources();
extern ActorProfile Object294_Profile;

// slot 293  profile @ 0x02124e34
void *Object293_create();
bool Object293_loadResources();
extern ActorProfile Object293_Profile;

// slot 292  profile @ 0x02124e7c
void *Object292_create();
bool Object292_loadResources();
extern ActorProfile Object292_Profile;

// slot 291  profile @ 0x02124ec4
void *Object291_create();
bool Object291_loadResources();
extern ActorProfile Object291_Profile;

// slot 290  profile @ 0x02124eac
void *Object290_create();
bool Object290_loadResources();
extern ActorProfile Object290_Profile;

// slot 289  profile @ 0x02124ea0
void *Object289_create();
bool Object289_loadResources();
extern ActorProfile Object289_Profile;

// slot 288  profile @ 0x02124edc
void *Object288_create();
bool Object288_loadResources();
extern ActorProfile Object288_Profile;

// slot 287  profile @ 0x02124e94
void *Object287_create();
bool Object287_loadResources();
extern ActorProfile Object287_Profile;
