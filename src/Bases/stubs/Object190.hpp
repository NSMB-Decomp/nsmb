#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 190  |  ov090  |  profile @ 0x02184ed8
class Object190 : public StageEntity {
public:
	static void *create();
	inline Object190() {};
	inline ~Object190() {};
};

extern ActorProfile Object190_Profile;

