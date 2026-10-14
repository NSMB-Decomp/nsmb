#pragma once
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 185  |  ov121  |  profile @ 0x0218e0d0
class Object185 : public StageEntity {
public:
	Model _3f4;
	u8 _pad0[0x24];

	static void *create();
	inline Object185() {};
	inline ~Object185() {};
};

extern ActorProfile Object185_Profile;

