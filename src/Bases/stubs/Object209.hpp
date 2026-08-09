#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 209  |  ov088  |  profile @ 0x02182578
class Object209 : public StageEntity {
public:
	static void *create();
	inline Object209() {};
	inline ~Object209() {};
};

extern ActorProfile Object209_Profile;

