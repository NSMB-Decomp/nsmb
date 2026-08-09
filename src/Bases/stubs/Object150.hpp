#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 150  |  ov058  |  profile @ 0x02173680
class Object150 : public StageEntity {
public:
	static void *create();
	inline Object150() {};
	inline ~Object150() {};
};

extern ActorProfile Object150_Profile;

