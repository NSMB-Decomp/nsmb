#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 48  |  ov100  |  profile @ 0x02189780
class Object48 : public StageEntity {
public:
	static void *create();
	inline Object48() {};
	inline ~Object48() {};
};

extern ActorProfile Object48_Profile;

