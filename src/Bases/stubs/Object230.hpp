#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 230  |  ov088  |  profile @ 0x02181f00
class Object230 : public StageEntity {
public:
	static void *create();
	inline Object230() {};
	inline ~Object230() {};
};

extern ActorProfile Object230_Profile;

