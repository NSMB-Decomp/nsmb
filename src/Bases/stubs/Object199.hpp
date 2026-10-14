#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 199  |  ov118  |  profile @ 0x02190034
class Object199 : public StageEntity {
public:
	static void *create();
	inline Object199() {};
	inline ~Object199() {};
};

extern ActorProfile Object199_Profile;

