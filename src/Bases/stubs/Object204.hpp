#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 204  |  ov059  |  profile @ 0x02174718
class Object204 : public StageEntity {
public:
	static void *create();
	inline Object204() {};
	inline ~Object204() {};
};

extern ActorProfile Object204_Profile;

