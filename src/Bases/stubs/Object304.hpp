#pragma once
#include "../StageEntity.hpp"

class Object304_Unknown
{
	u8 _pad0[0xd8];

      public:
	Object304_Unknown();
	~Object304_Unknown();
};

// MainProfileTable slot 304  |  ov052  |  profile @ 0x0215c67c
class Object304 : public Object
{
      public:
	Object304_Unknown _00[2];
	u8 _pad0[0x8];

	static void *create();
	Object304();
	inline ~Object304() {};

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual s32 onUpdate();
	virtual s32 onRender();
};

extern ObjectProfile Object304_Profile;
