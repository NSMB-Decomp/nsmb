#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 44  |  ov057  |  profile @ 0x02175560
class Object44 : public StageEntity {
public:
	static void *create();
	inline Object44() {};
	inline ~Object44() {};
};

extern ActorProfile Object44_Profile;

