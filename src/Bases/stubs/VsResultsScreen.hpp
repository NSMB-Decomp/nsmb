#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 10  |  ov052  |  profile @ 0x0215bb9c
class VsResultsScreen : public Scene {
public:
	u8 _pad[0xe8];
	static void *create();
	VsResultsScreen();
	inline ~VsResultsScreen() {};
};

extern ObjectProfile Object10_Profile;

