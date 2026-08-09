#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 115  |  ov040  |  profile @ 0x02146870
class Object115 : public StageEntity {
public:
	static void *create();
	inline Object115() {};
	inline ~Object115() {};
};

extern ActorProfile Object115_Profile;

