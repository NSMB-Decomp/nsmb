#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 114  |  ov040  |  profile @ 0x02146720
class Object114 : public StageEntity {
public:
	static void *create();
	inline Object114() {};
	inline ~Object114() {};
};

extern ActorProfile Object114_Profile;

