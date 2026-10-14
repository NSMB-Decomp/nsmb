#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 29  |  ov067  |  profile @ 0x02176770
class Object29 : public StageEntity {
public:
	static void *create();
	inline Object29() {};
	inline ~Object29() {};
};

extern ActorProfile Object29_Profile;

