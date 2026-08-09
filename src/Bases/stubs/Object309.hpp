#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

// MainProfileTable slot 309  |  ov009  |  profile @ 0x020daf4c
class Object309 : public Actor {
public:
	ModelAnm model;
	u8 _pad0[0x14];
	static void *create();
	inline Object309() {};
	inline ~Object309() {};
};

extern ActorProfile Object309_Profile;

