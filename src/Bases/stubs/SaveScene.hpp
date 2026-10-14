#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 7  |  ov008  |  profile @ 0x020e5820
class SaveScene : public Scene {
public:
	u8 _pad0[0x8];
	static void *create();
	inline SaveScene() {};
	inline ~SaveScene() {};
};

extern ObjectProfile Object7_Profile;

