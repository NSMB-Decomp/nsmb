#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 240  |  ov010  |  profile @ 0x02124014
class Object240 : public StageEntity {
public:
	static void *create();
	inline Object240() {};
	inline ~Object240() {};
};

extern ActorProfile Object240_Profile;

