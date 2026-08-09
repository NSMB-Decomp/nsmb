#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 326  |  ov001  |  profile @ 0x020ceb24
class Object326 : public StageEntity {
public:
	static void *create();
	inline Object326() {};
	inline ~Object326() {};
};

extern ActorProfile Object326_Profile;

