#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 170  |  ov048  |  profile @ 0x02148920
class Object170 : public StageEntity {
public:
	static void *create();
	inline Object170() {};
	inline ~Object170() {};
};

extern ActorProfile Object170_Profile;

