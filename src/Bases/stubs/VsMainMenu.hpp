#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 6  |  ov052  |  profile @ 0x0215bdec
class VsMainMenu : public Scene {
public:
	static void *create();
	inline VsMainMenu() {};
	inline ~VsMainMenu() {};
};

extern ActorProfile Object6_Profile;

