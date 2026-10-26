#pragma once
#include "../Actor.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/model.hpp"

// MainProfileTable slot 317  |  ov008  |  profile @ 0x020e59a8
class Object317 : public Actor {
public:
	static void *create();
	inline Object317() {};
	inline ~Object317() {};

	Model models[8];
	u8 _pad[0x1c];
};

extern ActorProfile Object317_Profile;

