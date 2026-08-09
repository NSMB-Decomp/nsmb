#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d//modelanm.hpp"

class Object313_Unknwon {
	public:
	u8 _pad[0x14];
	Vec3_32 _14;
	Object313_Unknwon();
	~Object313_Unknwon();
};

// MainProfileTable slot 313  |  ov009  |  profile @ 0x020db134
class Object313 : public Actor {
public:
	ModelAnm model;
	u32 _1c8;
	Object313_Unknwon _____[2];

	static void *create();
	Object313();
	inline ~Object313() {};
};

extern ActorProfile Object313_Profile;

