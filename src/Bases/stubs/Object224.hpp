#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 224  |  ov119  |  profile @ 0x0218e180
class Object224 : public StageEntity {
public:
	static void *create();
	inline Object224() {};
	inline ~Object224() {};
};

extern ActorProfile Object224_Profile;

