#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 136  |  ov050  |  profile @ 0x021483b0
class Object136 : public StageEntity {
public:
	ModelAnm _3fc;
	u8 _pad0[0x2c];
	
	static void *create();
	inline Object136() {};
	inline ~Object136() {};
};

extern ActorProfile Object136_Profile;

