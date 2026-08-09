#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 43  |  ov019  |  profile @ 0x02137458
class Object43 : public StageEntity {
public:
	static void *create();
	inline Object43() {};
	inline ~Object43() {};
};

extern ActorProfile Object43_Profile;

