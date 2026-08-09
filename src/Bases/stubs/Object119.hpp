#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 119  |  ov015  |  profile @ 0x02134728
class Object119 : public StageEntity {
public:
	static void *create();
	inline Object119() {};
	inline ~Object119() {};
};

extern ActorProfile Object119_Profile;

