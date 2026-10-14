#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/model.hpp"

class Object308_Model : public Model { // TODO: Is this in a seperate file?
	public:
	Object308_Model();
};

// MainProfileTable slot 308  |  ov009  |  profile @ 0x020daea0
class Object308 : public Actor {
public:
	Object308_Model model;
	u8 _pad0[0x368];
	static void *create();
	inline Object308() {};
	inline ~Object308() {};
};

extern ActorProfile Object308_Profile;

