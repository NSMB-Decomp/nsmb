#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 179  |  ov100  |  profile @ 0x021892d8
class Object179 : public StageEntity {
public:
	static void *create();
	inline Object179() {};
	inline ~Object179() {};
};

extern ActorProfile Object179_Profile;

