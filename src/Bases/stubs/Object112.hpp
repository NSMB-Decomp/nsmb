#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 112  |  ov046  |  profile @ 0x02148548
class Object112 : public StageEntity {
public:
	static void *create();
	inline Object112() {};
	inline ~Object112() {};
};

extern ActorProfile Object112_Profile;

