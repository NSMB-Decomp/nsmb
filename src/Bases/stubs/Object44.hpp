#pragma once
#include "../../graphics/3d/texture.hpp"
#include "../../Collision/Collider.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 44  |  ov057  |  profile @ 0x02175560
class Object44 : public StageEntity {
public:
	Collider _3f4;
	u8 _pad0[0xc];
	Texture _460;
	u8 _pad1[0x24];
	
	static void *create();
	inline Object44() {};
	inline ~Object44() {};
};

extern ActorProfile Object44_Profile;

