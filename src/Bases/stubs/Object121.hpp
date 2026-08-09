#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 121  |  ov054  |  profile @ 0x02170130
class Object121 : public StageEntity {
public:
	static void *create();
	inline Object121() {};
	inline ~Object121() {};
};

extern ActorProfile Object121_Profile;

