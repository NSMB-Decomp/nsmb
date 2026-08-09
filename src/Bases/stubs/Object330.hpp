#pragma once
#include "../../Minigame/MGScene.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 330  |  ov130  |  profile @ 0x02138f90
class Object330 : public MGScene {
public:
	static void *create();
	inline Object330() {};
	inline ~Object330() {};
};

extern ActorProfile Object330_Profile;

