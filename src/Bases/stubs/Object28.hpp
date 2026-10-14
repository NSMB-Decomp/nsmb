#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 28  |  ov025  |  profile @ 0x02141800
class Object28 : public StageEntity {
public:
	static void *create();
	inline Object28() {};
	inline ~Object28() {};
};

extern ActorProfile Object28_Profile;

// MainProfileTable slot 30  |  ov025  |  profile @ 0x0214180c
class Object30 : public StageEntity {
public:
	static void *create();
	inline Object30() {};
	inline ~Object30() {};
};

extern ActorProfile Object30_Profile;

