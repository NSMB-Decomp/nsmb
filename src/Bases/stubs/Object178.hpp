#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 178  |  ov020  |  profile @ 0x02133414
class Object178 : public StageEntity {
public:
	static void *create();
	inline Object178() {};
	inline ~Object178() {};
};

extern ActorProfile Object178_Profile;

