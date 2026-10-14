#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

class Object310_Unknown {
	Vec3_32 _28;
	u8 _pad0[0x28];
	public:
	Object310_Unknown();
	~Object310_Unknown();
};

// MainProfileTable slot 310  |  ov009  |  profile @ 0x020dafd0
class Object310 : public Actor {
public:
	ModelAnm modelanm;
	u32 _1c8;
	Object310_Unknown _a[5];
	static void *create();
	Object310();
	inline ~Object310() {};
};

extern ActorProfile Object310_Profile;

