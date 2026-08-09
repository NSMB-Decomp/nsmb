#pragma once
#include "../../Scenes/Scene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 14  |  ov004  |  profile @ 0x020cccc0
class GameOverScene : public Scene {
public:
	static void *create();
	GameOverScene();
	inline ~GameOverScene() {};
};

extern ObjectProfile GameOverScene_Profile;

