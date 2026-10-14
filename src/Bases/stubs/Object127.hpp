#pragma once
#include "../../graphics/3d/animation.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 127  |  ov071  |  profile @ 0x02179880
class Object127 : public StageEntity {
public:
	ModelAnm _3f4;
	Animation _49c;
	u8 _pad0[0x1c];
	
	static void *create();
	inline Object127() {};
	inline ~Object127() {};
};

extern ActorProfile Object127_Profile;

