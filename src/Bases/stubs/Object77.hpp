#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 77  |  ov012  |  profile @ 0x021321ec
class Object77 : public StageEntity {
public:
	static void *create();
	inline Object77() {};
	inline ~Object77() {};
};

extern ActorProfile Object77_Profile;

