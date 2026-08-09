#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 154  |  ov038  |  profile @ 0x02143490
class Object154 : public StageEntity {
public:
	static void *create();
	inline Object154() {};
	inline ~Object154() {};
};

extern ActorProfile Object154_Profile;

