#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 108  |  ov070  |  profile @ 0x02177620
class Object108 : public StageEntity {
public:
	static void *create();
	inline Object108() {};
	inline ~Object108() {};
};

extern ActorProfile Object108_Profile;

