#pragma once
#include "../../Collision/Collider.hpp"
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 203  |  ov059  |  profile @ 0x02174868
class Object203 : public StageEntity {
public:
	Model _3f4;
	Collider _484;
	u8 _pad0[0x24];

	static void *create();
	inline Object203() {};
	inline ~Object203() {};
};

extern ActorProfile Object203_Profile;

