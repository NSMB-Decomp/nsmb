#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 73  |  ov034  |  profile @ 0x02145388
class Object73 : public StageEntity {
public:
	static void *create();
	inline Object73() {};
	inline ~Object73() {};
};

extern ActorProfile Object73_Profile;

