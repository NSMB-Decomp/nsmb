#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 233  |  ov099  |  profile @ 0x02186370
class Object233 : public StageEntity {
public:
	Collider _3f4;
	u8 _pad1[0x2c];
	Texture _480;
	u8 _pad0[0x1c];

	static void *create();
	inline Object233() {};
	inline ~Object233() {};
};

extern ActorProfile Object233_Profile;

