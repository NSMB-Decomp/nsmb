#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 50  |  ov087  |  profile @ 0x0217f75c
class Object50 : public StageEntity {
public:
	static void *create();
	inline Object50() {};
	inline ~Object50() {};
};

extern ActorProfile Object50_Profile;

