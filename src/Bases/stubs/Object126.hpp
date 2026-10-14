#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 126  |  ov077  |  profile @ 0x0217c684
class Object126 : public StageEntity {
public:
	static void *create();
	inline Object126() {};
	inline ~Object126() {};
};

extern ActorProfile Object126_Profile;

