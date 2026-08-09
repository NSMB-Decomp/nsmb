#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 239  |  ov014  |  profile @ 0x021330e8
class Object239 : public StageEntity {
public:
	static void *create();
	inline Object239() {};
	inline ~Object239() {};
};

extern ActorProfile Object239_Profile;

