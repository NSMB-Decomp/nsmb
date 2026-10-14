#pragma once
#include "../../graphics/3d/animation.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 122  |  ov035  |  profile @ 0x02143c18
class Object122 : public StageEntity {
public:
	ModelAnm _3f4;
	Animation _49c;
	u8 _pad0[0x14];
	
	static void *create();
	inline Object122() {};
	inline ~Object122() {};
};

extern ActorProfile Object122_Profile;

