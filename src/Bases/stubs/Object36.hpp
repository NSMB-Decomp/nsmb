#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 36  |  ov012  |  profile @ 0x021320a0
class Object36 : public StageEntity {
public:
	static void *create();
	inline Object36() {};
	inline ~Object36() {};
};

extern ActorProfile Object36_Profile;

