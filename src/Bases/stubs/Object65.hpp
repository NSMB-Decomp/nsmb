#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 65  |  ov024  |  profile @ 0x0213f928
class Object65 : public StageEntity {
public:
	static void *create();
	inline Object65() {};
	inline ~Object65() {};
};

extern ActorProfile Object65_Profile;

