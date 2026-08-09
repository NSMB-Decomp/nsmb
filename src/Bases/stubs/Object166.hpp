#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 166  |  ov010  |  profile @ 0x02125f34
class Object166 : public StageEntity {
public:
	static void *create();
	inline Object166() {};
	inline ~Object166() {};
};

extern ActorProfile Object166_Profile;

