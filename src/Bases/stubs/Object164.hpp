#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 164  |  ov100  |  profile @ 0x02189650
class Object164 : public StageEntity {
public:
	static void *create();
	inline Object164() {};
	inline ~Object164() {};
};

extern ActorProfile Object164_Profile;

