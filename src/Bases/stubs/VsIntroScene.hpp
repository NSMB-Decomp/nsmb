#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 15  |  ov052  |  profile @ 0x0215b5c0
class VsIntroScene : public Scene {
public:
	u8 _pad[0x4];
	static void *create();
	VsIntroScene();
	inline ~VsIntroScene() {};
};

extern ObjectProfile Object15_Profile;

