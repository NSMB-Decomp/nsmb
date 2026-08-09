#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 122  |  ov035  |  profile @ 0x02143c18
class Object122 : public StageEntity {
public:
	static void *create();
	inline Object122() {};
	inline ~Object122() {};
};

extern ActorProfile Object122_Profile;

