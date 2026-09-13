#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 266  |  ov040  |  profile @ 0x02146ad8
class Object266 : public StageEntity {
public:
	static void *create();
	inline Object266() {};
	inline ~Object266() {};
    bool onUpdate_0();
    s32 onCreate();
};

extern ActorProfile Object266_Profile;

