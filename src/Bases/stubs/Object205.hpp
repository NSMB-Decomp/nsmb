#pragma once
#include "../../Collision/Collider.hpp"
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 205  |  ov059  |  profile @ 0x02174990
class Object205 : public StageEntity {
public:
	Model _3f4;
	Collider _484;
	u8 _pad0[0x1c];
	
	static void *create();
	inline Object205() {};
	inline ~Object205() {};
};

extern ActorProfile Object205_Profile;

