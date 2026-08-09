#pragma once
#include "../../graphics/3d/animation.hpp"
#include "../../graphics/3d/model.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 109  |  ov070  |  profile @ 0x02177740
class Object109 : public StageEntity {
public:
	Model _3f4;
	Animation _484;
	u8 _pad0[0xc];
	
	static void *create();
	inline Object109() {};
	inline ~Object109() {};
};

extern ActorProfile Object109_Profile;

