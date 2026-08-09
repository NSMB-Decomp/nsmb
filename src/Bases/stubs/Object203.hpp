#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 203  |  ov059  |  profile @ 0x02174868
class Object203 : public StageEntity {
public:
	static void *create();
	inline Object203() {};
	inline ~Object203() {};
};

extern ActorProfile Object203_Profile;

