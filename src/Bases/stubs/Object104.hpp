#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 104  |  ov121  |  profile @ 0x0218e1f0
class Object104 : public StageEntity {
public:
    u8 _3f2;
    u8 _3f3;
	u8 _pad0[0x2];

	static void *create();
	inline Object104() {};
	inline ~Object104() {};

    s32 onDestroy();
    void pendingDestroy();
    bool onUpdate_0();
    s32 onCreate();
};

extern ActorProfile Object104_Profile;

