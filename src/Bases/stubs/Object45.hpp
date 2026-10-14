#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 45  |  ov057  |  profile @ 0x02175750
class Object45 : public StageEntity {
public:
	static void *create();
	inline Object45() {};
	inline ~Object45() {};
};

extern ActorProfile Object45_Profile;

