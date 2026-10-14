#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 12  |  ov008  |  profile @ 0x020e9b88
class EndingScene : public Scene {
public:
	u8 _pad0[0x4];
	static void *create();
	inline EndingScene() {};
	inline ~EndingScene() {};
};

extern ObjectProfile Object12_Profile;

