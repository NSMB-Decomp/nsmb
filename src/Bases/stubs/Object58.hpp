#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 58  |  ov042  |  profile @ 0x02151c38
class Object58 : public StageEntity {
public:
	static void *create();
	inline Object58() {};
	inline ~Object58() {};
};

extern ActorProfile Object58_Profile;

