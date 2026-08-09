#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 168  |  ov020  |  profile @ 0x02133090
class Object168 : public StageEntity {
public:
	static void *create();
	inline Object168() {};
	inline ~Object168() {};
};

extern ActorProfile Object168_Profile;

