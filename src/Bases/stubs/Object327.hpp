#pragma once
#include "../../Minigame/MGScene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 327  |  arm9  |  profile @ 0x0203d320
class Object327 : public MGScene {
public:
	u8 _pad0[0x20];

	static void *create();
	inline Object327() {};
	inline ~Object327() {};
};

extern ObjectProfile Object327_Profile;

